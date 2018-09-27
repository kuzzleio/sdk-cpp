#!/usr/bin/env bash
set -e

mkdir ./build/{lib,include}
cp -fr ./include/*.hpp ./build/include
cp sdk-c/include/kuzzlesdk.h ./build/include/kuzzlesdk.h
cp sdk-c/include/sdk_wrappers_internal.h ./build/include/
cp ./build/*.{so,a}  ./build/lib/
mkdir deploy
cd build
tar cfz ../deploy/kuzzlesdk-cpp-$ARCH.tar.gz lib include

