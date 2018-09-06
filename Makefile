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

SDKGOPATH = go$(PATHSEP)src$(PATHSEP)github.com$(PATHSEP)kuzzleio$(PATHSEP)sdk-go
CGOPATH = cgo$(PATHSEP)kuzzle
PATHSEP = $(strip $(SEP))
ROOTOUTDIR = $(ROOT_DIR)build
GOFLAGS = -buildmode=c-archive
GOSRC = .$(PATHSEP)cgo$(PATHSEP)kuzzle$(PATHSEP)
GOTARGETDIR = $(ROOTOUTDIR)/c
GOTARGET = $(GOTARGETDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB)
GOTARGETSO = $(GOTARGETDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(DYNLIB)
CPPDIR = $(ROOT_DIR)cpp
HEADERSDIR = $(ROOT_DIR)include

CPPFLAGS = -g -fPIC -std=c++11
INCS = -I$(HEADERSDIR) -I$(CPPDIR) -I$(ROOT_DIR)templates -I$(GOTARGETDIR)
LDFLAGS = -L$(GOTARGETDIR)
LIBS = -lkuzzlesdk
SRCS = kcore_wrap.cxx
OBJS = $(SRCS:.cxx=.o)

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
	$(CXX) -fPIC -c $< -o $@ $(CPPFLAGS) -I.$(PATHSEP)include -I.$(PATHSEP)build$(PATHSEP)c$(PATHSEP) -L.$(PATHSEP)build$(PATHSEP)c -lkuzzlesdk

core:
ifneq ($(OS),Windows_NT)
ifeq ($(wildcard $(GOCC)),)
	$(error "Unable to find go compiler")
endif
endif
	cd $(SDKGOPATH) && go get .$(PATHSEP)...
	cd $(SDKGOPATH)$(PATHSEP)internal$(PATHSEP)wrappers && $(GOCC) build -o $(GOTARGET) $(GOFLAGS) $(GOSRC)
	cd $(SDKGOPATH)$(PATHSEP)internal$(PATHSEP)wrappers && $(GOCC) build -o $(GOTARGETSO) $(GOFLAGS) $(GOSRC)
ifeq ($(OS),Windows_NT)
	$(MV) $(subst /,\,$(GOTARGETDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk.h) kuzzle.h
else
	$(MV) $(GOTARGETDIR)$(PATHSEP)$(LIB_PREFIX)kuzzlesdk.h $(GOTARGETDIR)$(PATHSEP)kuzzle.h
endif

makedir:
ifeq ($(OS),Windows_NT)
	@if not exist $(subst /,\,$(OUTDIR)) mkdir $(subst /,\,$(OUTDIR))
else
	mkdir -p $(OUTDIR)
endif

cpp: OUTDIR = $(ROOTOUTDIR)/cpp
cpp: LANGUAGE = c++
cpp: export GOPATH = $(ROOT_DIR)go
cpp: makedir core $(CPPSDK)
		ar rvs $(OUTDIR)$(PATHSEP)libcpp$(STATICLIB) src$(PATHSEP)*.o
		$(CXX) -shared -fPIC -o $(OUTDIR)$(PATHSEP)libcpp$(DYNLIB) -Wl,--whole-archive $(OUTDIR)$(PATHSEP)libcpp$(STATICLIB) build$(PATHSEP)c$(PATHSEP)$(LIB_PREFIX)kuzzlesdk$(STATICLIB) -Wl,--no-whole-archive

clean:
ifeq ($(OS),Windows_NT)
	if exist build$(PATHSEP)c $(RRM) build$(PATHSEP)cpp
	$(RRM) src$(PATHSEP)*.o
else
	$(RRM) build$(PATHSEP)c
	$(RRM) build$(PATHSEP)cpp
	$(RRM) kcore_wrap.cxx kcore_wrap.h kcore_wrap.o
	$(RRM) src$(PATHSEP)*.o
endif
.PHONY: all cpp core clean 


.DEFAULT_GOAL := all
