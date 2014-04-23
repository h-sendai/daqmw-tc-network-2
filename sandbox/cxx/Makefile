CC = g++
PROG = decode
CXXFLAGS = -g -O2 -Wall
# LDLIBS += -L/usr/local/lib/ -lmylib

OBJS += decode.o
OBJS += decode_data.o

all: $(PROG)

$(PROG): $(OBJS)

clean:
	rm -f *.o $(PROG)
