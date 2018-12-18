VERSION = 1.0.0
SHELL = /bin/bash

ROOT_DIR = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
ifeq ($(OS),Windows_NT)
	STATICLIB = .lib
	DYNLIB = .dll
	GOROOT ?= C:/Go
	GOCC ?= $(GOROOT)bin\go
	SEP = \\
	RM = del /Q /F /S
	RRM = rmdir /S /Q
	MV = rename
	CMDSEP = &
	ROOT_DIR_CLEAN = $(subst /,\,$(ROOT_DIR))
	LIB_PREFIX =
else
	STATICLIB = .a
	DYNLIB = .so
	GOROOT ?= /usr/local/go
	GOCC ?= $(GOROOT)/bin/go
	SEP = /
	RM = rm -f
	RRM = rm -f -r
	MV = mv -f
	ROOT_DIR_CLEAN = $(ROOT_DIR)
	LIB_PREFIX = lib
	ARCH?=$(shell uname -p)
endif

SDK_FOLDER_NAME=kuzzle-cpp-sdk

export GOPATH = $(ROOT_DIR)go

PATHSEP = $(strip $(SEP))
BUILD_DIR = build
AR ?= ar

CXXFLAGS = -g -fPIC -std=c++11 -MMD \
	-I.$(PATHSEP)include \
	-I.$(PATHSEP)sdk-c$(PATHSEP)build$(PATHSEP)kuzzle-c-sdk$(PATHSEP)include \
	-L.$(PATHSEP)sdk-c$(PATHSEP)build$(PATHSEP)kuzzle-c-sdk$(PATHSEP)lib

LDFLAGS = -lkuzzlesdk

SOURCES = $(wildcard src$(PATHSEP)*.cpp)

OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)
DEPENDS = $(OBJECTS:%.o=%.d)

all: $(BUILD_DIR)/cpp

-include ${DEPENDS}

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(LDFLAGS)

$(BUILD_DIR):
ifeq ($(OS),Windows_NT)
	@if not exist $(subst /,\,$(BUILD_DIR)) mkdir $(subst /,\,$(BUILD_DIR))
else
	mkdir -p $@
endif

update_submodule:
	cd sdk-c/go/src/github.com/kuzzleio/sdk-go && git submodule init && git submodule update

make_c_sdk:
	cd sdk-c && $(MAKE)

$(BUILD_DIR)/cpp: $(BUILD_DIR) make_c_sdk $(OBJECTS)
	$(AR) rvs $(BUILD_DIR)$(PATHSEP)libkuzzlesdk$(STATICLIB).$(VERSION) $(OBJECTS)
	$(CXX) -shared -fPIC -o $(BUILD_DIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION) -Wl,--whole-archive $(BUILD_DIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION) sdk-c$(PATHSEP)build$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB) -Wl,--no-whole-archive
	cd $(BUILD_DIR) && ln -srf $(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION) $(LIB_PREFIX)kuzzlesdk$(DYNLIB)
	cd $(BUILD_DIR) && ln -srf $(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION) $(LIB_PREFIX)kuzzlesdk$(STATICLIB)
	mkdir -p $(BUILD_DIR)$(PATHSEP)$(SDK_FOLDER_NAME)/lib
	mkdir -p $(BUILD_DIR)$(PATHSEP)$(SDK_FOLDER_NAME)/include

	cp -fr include/*  $(BUILD_DIR)$(PATHSEP)$(SDK_FOLDER_NAME)/include
	cp -ra sdk-c$(PATHSEP)build/kuzzle-c-sdk/include/* $(BUILD_DIR)$(PATHSEP)$(SDK_FOLDER_NAME)/include
	cp -a $(BUILD_DIR)$(PATHSEP)*.so*  $(BUILD_DIR)$(PATHSEP)*.a* $(BUILD_DIR)$(PATHSEP)$(SDK_FOLDER_NAME)/lib
	@touch $@

package: $(BUILD_DIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION) $(BUILD_DIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION)
	mkdir -p deploy && cd $(BUILD_DIR) && tar cfz ..$(PATHSEP)deploy$(PATHSEP)kuzzlesdk-cpp-$(VERSION)-$(ARCH).tar.gz $(SDK_FOLDER_NAME)

build_test: $(BUILD_DIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION) $(BUILD_DIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION)
	cd test && ./build_cpp_tests.sh

run_test:
	SKIPBUILD=1 ./run-tests.sh

clean:
	cd sdk-c && make clean
ifeq ($(OS),Windows_NT)
	$(RRM) $(BUILD_DIR)
	$(RRM) $(ROOT_DIR)$(PATHSEP)deploy
	$(RRM) $(ROOT_DIR)$(PATHSEP)test$(PATHSEP)_build_cpp_tests
else
	$(RRM) $(BUILD_DIR) deploy test$(PATHSEP)_build_cpp_tests
endif
.PHONY: all core clean run_test


.DEFAULT_GOAL := all
