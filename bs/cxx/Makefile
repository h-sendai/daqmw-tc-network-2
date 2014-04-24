CC = g++
PROG = readfile
CXXFLAGS = -pg -g -O2 -Wall
LDFLAGS += -pg
# LDLIBS += -L/usr/local/lib/ -lmylib

OBJS += $(PROG).o
OBJS += RawDataPacket.o

all: $(PROG)

$(PROG): $(OBJS)
RawDataPacket.o: RawDataPacket.h RawDataPacket.cpp

clean:
	rm -f *.o $(PROG)
