#!/usr/bin/env bash

set -e
cd test

export CUCUMBER_HOST='localhost'
export CUCUMBER_PORT='3902'

VALGRIND_LOGFILE='./_build_cpp_tests/valgrind_report.log'

# initializes the valgrind suppression arguments
for supp in ./valgrind.*.supp; do
  VALGRIND_SUPPR="${VALGRIND_SUPPR} --suppressions=${supp}"
done

FEATURE_FILE=$1

if [ -z "${SKIPBUILD}" -o "${SKIPBUILD}" = 0 ]; then
  ./build_cpp_tests.sh
fi

VALGRIND=""

if [ -z "${SKIPVALGRIND}" -o "${SKIPVALGRIND}" = 0 ]; then
  valgrind --leak-check=full --show-reachable=yes --gen-suppressions=all ${VALGRIND_SUPPR} --log-file=${VALGRIND_LOGFILE} ./_build_cpp_tests/KuzzleSDKStepDefs &

  # Should generally be enough to let valgrind initialize
  # and start the server.
  # If not, there is a retry mechanism fallback below
  sleep 2
else
  ./_build_cpp_tests/KuzzleSDKStepDefs &
fi

CMD="cucumber"

if [ ! -z "$FEATURE_FILE" ]; then
  CMD="${CMD} ./features/sdk-features/$FEATURE_FILE"
fi

${CMD}
CUCUMBER_STATUS=$?

# Restart Cucumber if the wire server wasn't ready
# We cannot check the connection port beforehand (e.g. with netcat),
# because the wire protocol makes the step definitions exit whenever
# a disconnection is detected
retries=5

while [ ${CUCUMBER_STATUS} -eq 2 ]; do
  if [ ${retries} -eq 0 ]; then
    echo "No more retries available. Aborting."
    exit 2
  fi

  retries=$((retries-1))

  echo "Cucumber Wire connection problem detected."
  echo "Retrying in 5 seconds (${retries} retries left)."
  sleep 5

  ${CMD}
  CUCUMBER_STATUS=$?
done

cd -

exit ${CUCUMBER_STATUS}
