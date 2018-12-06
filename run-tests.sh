#!/usr/bin/env bash

set -e

cd test

FEATURE_FILE=$1

./build_cpp_tests.sh
./_build_cpp_tests/KuzzleSDKStepDefs &

if [ ! -z "$FEATURE_FILE" ]; then
  bundle exec cucumber ./features/sdk-features/$FEATURE_FILE
else
  bundle exec cucumber
fi

cd -
