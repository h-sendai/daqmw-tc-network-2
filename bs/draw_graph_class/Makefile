# First we check ROOTSYS environment variable

ifndef ROOTSYS
$(error This program requires ROOTSYS environment variable\
but does not defined.  Please define ROOTSYS as follows at\
shell prompt: "export ROOTSYS=/usr/local/root".  If you don't install\
ROOT in /usr/local/root, please substitute your ROOT root directory)
endif

# Second we check root-config command to lookup the ROOT is installed or not.

ROOT_INC = $(shell ${ROOTSYS}/bin/root-config --incdir)
ifeq ($(strip $(ROOT_INC)),)
$(error Cannot execute root-config command at $$ROOTSYS/bin/root-config.\
Please install ROOT program.\
Consult at http://root.cern.ch to install ROOT)
endif

ROOT_VERSION = $(shell ${ROOTSYS}/bin/root-config --version | sed -e 's/\..*//')
EL_VERSION   = $(shell lsb_release -sr | sed -e 's/\..*//')
ifeq ($(strip $(EL_VERSION)), 7)
ifeq ($(strip $(ROOT_VERSION)),6)
CXXFLAGS += -std=gnu++11
endif
endif

CPPFLAGS += -I$(shell ${ROOTSYS}/bin/root-config --incdir)
LDLIBS   += $(shell ${ROOTSYS}/bin/root-config --libs)

CC = g++
PROG = draw-graph-class
CXXFLAGS += -g -O2 -Wall
# LDLIBS += -L/usr/local/lib -lmylib
# LDLIBS += -lrt
# LDFLAGS += -pthread

all: $(PROG)
OBJS += $(PROG).o
OBJS += MyGraph.o
$(PROG): $(OBJS)

MyGraph.o: MyGraph.cpp MyGraph.h

clean:
	rm -f *.o $(PROG)
