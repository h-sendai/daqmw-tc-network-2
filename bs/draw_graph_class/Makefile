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


CC = g++
PROG = draw-graph-class
CXXFLAGS += -g -O2 -Wall
CXXFLAGS += $(shell ${ROOTSYS}/bin/root-config --cflags)
LDLIBS   += $(shell ${ROOTSYS}/bin/root-config --libs)
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
