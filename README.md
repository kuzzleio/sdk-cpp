Official Kuzzle CPP SDK
======

## About Kuzzle

A backend software, self-hostable and ready to use to power modern apps.

You can access the Kuzzle repository on [Github](https://github.com/kuzzleio/kuzzle)

## SDK Documentation

The complete SDK documentation is available [here](http://docs.kuzzle.io/sdk-reference/cpp/1)

## Protocol used

The CPP SDK implement the websocket protocol.

## Installation

### Clone the depot

```sh
git clone --recursive git@github.com:kuzzleio/sdk-cpp.git
```

### Build

```
make
```

You should know have the SDK in the build directory.


## Run tests

The tests uses cucumber, so please ensure that you have ruby in your PATH.
First make the SDK, install `Bundler`, install cucumber and run a Kuzzle stack.  

```bash
gem install bundler
cd test
bundle install
.ci/start_kuzzle.sh
```

Then run features tests
```bash
# Run all features tests
./run-functionnal-testing.sh

# Run only one feature file
./run-functional-testing.sh collection.feature
```
