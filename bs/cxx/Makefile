CC = g++
PROG = readfile
CXXFLAGS = -g -O2 -Wall
# LDLIBS += -L/usr/local/lib/ -lmylib

OBJS += $(PROG).o

all: $(PROG)

$(PROG): $(OBJS)
$(OBJS): RawDataPacket.h $(PROG).cpp

clean:
	rm -f *.o $(PROG)
