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

CXXFLAGS = -g -fPIC -std=c++11 -I.$(PATHSEP)include -I.$(PATHSEP)sdk-c$(PATHSEP)include$(PATHSEP) -I.$(PATHSEP)sdk-c$(PATHSEP)build$(PATHSEP) -L.$(PATHSEP)sdk-c$(PATHSEP)build
LDFLAGS = -lkuzzlesdk

CPP_SDK_SRCS = src$(PATHSEP)kuzzle.cpp \
					src$(PATHSEP)document.cpp \
					src$(PATHSEP)collection.cpp \
					src$(PATHSEP)realtime.cpp \
					src$(PATHSEP)auth.cpp \
					src$(PATHSEP)server.cpp \
					src$(PATHSEP)index.cpp

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
cpp: makedir update_submodule make_c_sdk $(CPPSDK)
		ar rvs $(ROOTOUTDIR)$(PATHSEP)libkuzzlesdk$(STATICLIB) src$(PATHSEP)*.o
		$(CXX) -shared -fPIC -o $(ROOTOUTDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(DYNLIB) -Wl,--whole-archive $(ROOTOUTDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB) sdk-c$(PATHSEP)build$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB) -Wl,--no-whole-archive
		cd $(ROOTOUTDIR) && mv $(LIB_PREFIX)kuzzlesdk$(STATICLIB) $(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION) && mv $(LIB_PREFIX)kuzzlesdk$(DYNLIB) $(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION)
		cd $(ROOTOUTDIR) && ln -s $(LIB_PREFIX)kuzzlesdk$(DYNLIB).$(VERSION) $(LIB_PREFIX)kuzzlesdk$(DYNLIB)
		cd $(ROOTOUTDIR) && ln -s $(LIB_PREFIX)kuzzlesdk$(STATICLIB).$(VERSION) $(LIB_PREFIX)kuzzlesdk$(STATICLIB)

clean:
	cd sdk-c && make clean'
ifeq ($(OS),Windows_NT)
	$(RRM) $(ROOTOUTDIR)
	$(RRM) src$(PATHSEP)*.o
else
	$(RRM) $(ROOTOUTDIR) src/*.o
endif
.PHONY: all cpp core clean 


.DEFAULT_GOAL := all
