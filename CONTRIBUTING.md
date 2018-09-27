# How to contribute to Kuzzle CPP SDK

Here are a few rules and guidelines to follow if you want to contribute to Kuzzle CPP SDK and, more importantly, if you want to see your pull requests accepted by Kuzzle team.    

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
