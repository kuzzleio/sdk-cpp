#/bin/bash
set -e
cmake -E make_directory _build_cpp_tests
cmake -E chdir _build_cpp_tests cmake ../features/step_definitions
cmake --build _build_cpp_tests -- -j2
