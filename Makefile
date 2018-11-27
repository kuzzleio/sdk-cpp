VERSION = 1.0.0

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
endif

PATHSEP = $(strip $(SEP))
ROOTOUTDIR = $(ROOT_DIR)build
CPPDIR = $(ROOT_DIR)cpp
HEADERSDIR = $(ROOT_DIR)include
AR ?= ar

CXXFLAGS = -g -fPIC -std=c++11 -I.$(PATHSEP)include -I.$(PATHSEP)sdk-c$(PATHSEP)include$(PATHSEP) -I.$(PATHSEP)sdk-c$(PATHSEP)build$(PATHSEP) -L.$(PATHSEP)sdk-c$(PATHSEP)build
LDFLAGS = -lkuzzlesdk

CPP_SDK_SRCS = src$(PATHSEP)kuzzle.cpp \
					src$(PATHSEP)auth.cpp \
					src$(PATHSEP)collection.cpp \
					src$(PATHSEP)document.cpp \
					src$(PATHSEP)index.cpp \
					src$(PATHSEP)realtime.cpp \
					src$(PATHSEP)search_result.cpp \
					src$(PATHSEP)server.cpp \
					src$(PATHSEP)index.cpp \
					src$(PATHSEP)websocket.cpp \
					src$(PATHSEP)default_constructors.cpp \
					src$(PATHSEP)specification_search_result.cpp

CPPSDK = $(CPP_SDK_SRCS:%.cpp=%.o)

all: cpp

%.o: %.cpp
	$(CXX) -fPIC -c $< -o $@ $(CXXFLAGS) $(LDFLAGS)

makedir:
ifeq ($(OS),Windows_NT)
	@if not exist $(subst /,\,$(ROOTOUTDIR)) mkdir $(subst /,\,$(ROOTOUTDIR))
else
	mkdir -p $(ROOTOUTDIR)
endif

update_submodule:
	cd sdk-c/go/src/github.com/kuzzleio/sdk-go && git submodule init && git submodule update

make_c_sdk:
	cd sdk-c && $(MAKE)

cpp: export GOPATH = $(ROOT_DIR)go
cpp: makedir make_c_sdk $(CPPSDK)
		$(AR) rvs $(ROOTOUTDIR)$(PATHSEP)libkuzzlesdk$(STATICLIB) src$(PATHSEP)*.o
		$(CXX) -shared -fPIC -o $(ROOTOUTDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(DYNLIB) -Wl,--whole-archive $(ROOTOUTDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB) sdk-c$(PATHSEP)build$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB) -Wl,--no-whole-archive
		cd $(ROOTOUTDIR) && mv $(LIB_PREFIX)kuzzlesdk$(STATICLIB) $(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION) && mv $(LIB_PREFIX)kuzzlesdk$(DYNLIB) $(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION)
		cd $(ROOTOUTDIR) && ln -sr $(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION) $(LIB_PREFIX)kuzzlesdk$(DYNLIB)
		cd $(ROOTOUTDIR) && ln -sr $(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION) $(LIB_PREFIX)kuzzlesdk$(STATICLIB)

package: $(ROOTOUTDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION) $(ROOTOUTDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION)
	mkdir $(ROOTOUTDIR)$(PATHSEP)lib
	mkdir $(ROOTOUTDIR)$(PATHSEP)include
	cp -fr $(ROOT_DIR)$(PATHSEP)include$(PATHSEP)*.hpp $(ROOTOUTDIR)$(PATHSEP)include
	cp $(ROOT_DIR)$(PATHSEP)sdk-c$(PATHSEP)include$(PATHSEP)kuzzlesdk.h $(ROOTOUTDIR)$(PATHSEP)include
	cp $(ROOT_DIR)$(PATHSEP)sdk-c$(PATHSEP)include$(PATHSEP)sdk_wrappers_internal.h $(ROOTOUTDIR)$(PATHSEP)include
	cp $(ROOT_DIR)$(PATHSEP)sdk-c$(PATHSEP)include$(PATHSEP)protocol.h $(ROOTOUTDIR)$(PATHSEP)include
	cp $(ROOT_DIR)$(PATHSEP)sdk-c$(PATHSEP)build$(PATHSEP)kuzzle.h $(ROOTOUTDIR)$(PATHSEP)include
	cp $(ROOTOUTDIR)$(PATHSEP)*.so  $(ROOTOUTDIR)$(PATHSEP)lib
	cp $(ROOTOUTDIR)$(PATHSEP)*.a  $(ROOTOUTDIR)$(PATHSEP)lib

	mkdir deploy && cd $(ROOTOUTDIR) && tar cfz ..$(PATHSEP)deploy$(PATHSEP)kuzzlesdk-cpp-$(VERSION)-$(ARCH).tar.gz lib include

build_test: $(ROOTOUTDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION) $(ROOTOUTDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION)
	cd $(ROOT_DIR)$(PATHSEP)test && sh build_cpp_tests.sh

run_test: $(ROOT_DIR)$(PATHSEP)test$(PATHSEP)_build_cpp_tests$(PATHSEP)KuzzleSDKStepDefs
	cd $(ROOT_DIR)$(PATHSEP)test && .$(PATHSEP)_build_cpp_tests$(PATHSEP)KuzzleSDKStepDefs > /dev/null &
	cd $(ROOT_DIR)$(PATHSEP)test && cucumber

clean:
	cd sdk-c && make clean
ifeq ($(OS),Windows_NT)
	$(RRM) $(ROOTOUTDIR)
	$(RRM) src$(PATHSEP)*.o
	$(RRM) $(ROOT_DIR)$(PATHSEP)deploy
	$(RRM) $(ROOT_DIR)$(PATHSEP)test$(PATHSEP)_build_cpp_tests
else
	$(RRM) $(ROOTOUTDIR) src/*.o $(ROOT_DIR)$(PATHSEP)deploy $(ROOT_DIR)$(PATHSEP)test$(PATHSEP)_build_cpp_tests
endif
.PHONY: all cpp core clean


.DEFAULT_GOAL := all
