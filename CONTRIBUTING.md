# How to contribute to the CPP SDK

Here are a few rules and guidelines to follow if you want to contribute to the Java SDK and, more importantly, if you want to see your pull requests accepted by the  Kuzzle team.

## Build the SDK

You can use this Docker image to build the SDK:
```
docker run --rm -it --network ci_default --link kuzzle -v "$(pwd)":/mnt kuzzleio/sdk-cross:gcc make clean all
```

### Build with MSVC

MSVC does not support linking with DLLs, you must use the workaround described here: https://stackoverflow.com/questions/9946322/how-to-generate-an-import-library-lib-file-from-a-dll

In addition, you must also use the `-buildmode=c-shared` compilation option for the SDK to work properly.

## Compile with the SDK

Use this commande to compile a cpp source file with the builded SDK:
```
g++ -std=c++11 source.cpp -Isdk-c/build/kuzzle-c-sdk/include -Iinclude -L./build/ -lkuzzlesdk -lpthread
```

Then run the compiled program with: `LD_LIBRARY_PATH=./build ./a.out`

## Tools

This SDK inherits from the following repositories, linked as git submodules: sdk-c, sdk-go.
Whenever significant changes are applied to the parent SDKs, you need to align the linked submodules accordingly.
You can use `align-submodules.sh` script to achieve this. (e.g.: `./align-submodules.sh 1-dev` to align all submodules on `1-dev` branch)

## Running Tests

Tests are handled by [cucumber](https://cucumber.io/).
First build the SDK, install `Bundler`, install cucumber and run a Kuzzle stack:

```bash
gem install bundler
cd test
bundle install
cd ..
bash .ci/start_kuzzle.sh
```

Then run features tests
```bash
# Run all features tests
./run-tests.sh

# Run only one feature file
./run-tests.sh collection.feature

```

You can also use the Docker container:
```bash
# Run all features tests
docker run --rm -it --network ci_default --link kuzzle -v "$(pwd)":/mnt kuzzleio/sdk-cross:gcc make build_test run_test
```
