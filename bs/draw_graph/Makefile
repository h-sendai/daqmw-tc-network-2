CC = g++
PROG = draw_graph
CXXFLAGS = -g -O2 -Wall
CPPFLAGS += -I$(shell ${ROOTSYS}/bin/root-config --incdir)
LDLIBS   += $(shell ${ROOTSYS}/bin/root-config --glibs)

# LDLIBS += -L/usr/local/lib/ -lmylib

OBJS += $(PROG).o

all: $(PROG)

$(PROG): $(OBJS)

clean:
	rm -f *.o $(PROG)
