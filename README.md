[![Build Status](https://travis-ci.org/kuzzleio/sdk-cpp.svg?branch=master)](https://travis-ci.org/kuzzleio/sdk-cpp)

Official Kuzzle C++ SDK
======

# About Kuzzle

A backend software, self-hostable and ready to use to power modern apps.

You can access the Kuzzle repository on [Github](https://github.com/kuzzleio/kuzzle)

# SDK Documentation

The complete SDK documentation is available [here](http://docs.kuzzle.io/sdk-reference/)

# Protocol used

The C++ SDK implements the websocket protocol.

# Build

Execute the following snippet to clone the GIT repository, and build the SDK. It will then be available in the "build/" directory

```sh
git clone --recursive git@github.com:kuzzleio/sdk-cpp.git
cd sdk-cpp
git submodule update --init --recursive
make
```

# Installation

You can find prebuilt SDK's for each version and architecture:

arm64: https://dl.kuzzle.io/sdk/c/master/kuzzlesdk-cpp-aarch64-1.0.0.tar.gz

arm32: https://dl.kuzzle.io/sdk/c/master/kuzzlesdk-cpp-armhf-1.0.0.tar.gz

amd64: https://dl.kuzzle.io/sdk/c/master/kuzzlesdk-cpp-amd64-1.0.0.tar.gz

x86:  https://dl.kuzzle.io/sdk/c/master/kuzzlesdk-cpp-x86-1.0.0.tar.gz

# Tests

To manually run the bundled tests on this SDK, you need the following dependencies installed:

- boost libraries (https://www.boost.org/)
- cucumber, cmake & valgrind: `sudo apt install -y cmake cucumber valgrind`

Once done, you can start the functional tests with the following command:

```
./run-tests.sh
```

The test results are printed to the standard output.

Functional tests are monitored by valgrind. The report is available here: `./test/_build_cpp_tests/valgrind_report.log`
