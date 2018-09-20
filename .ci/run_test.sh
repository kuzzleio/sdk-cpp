#!/usr/bin/env bash
set -e
cd test
./_build_cpp_tests/KuzzleSDKStepDefs > /dev/null &
cucumber
cd -
