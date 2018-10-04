# How to contribute to the CPP SDK

Here are a few rules and guidelines to follow if you want to contribute to the CPP SDK and, more importantly, if you want to see your pull requests accepted by Kuzzle team.

## Tools

We use git submodules to link the sdk-go and the sdk-c.  
When you are developing a new functionality that had implications on the other SDK, you should align all your submodules on your development branch.  
You can use `align-submodules.sh` script to achieve this. (Eg: `./align-submodules.sh 1-dev` to align all submodules on `1-dev` branch)


To build the SDK, you can use this Docker image to build the SDK:  
```
docker run --rm -it --network ci_default --link kuzzle -v "$(pwd)":/mnt kuzzleio/sdk-cross:gcc make all
```

## Running Tests

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

You can also use the Docker container:
```bash
# Run all features tests
docker run --rm -it --network ci_default --link kuzzle -v "$(pwd)":/mnt kuzzleio/sdk-cross:gcc make build_test run_test
```
