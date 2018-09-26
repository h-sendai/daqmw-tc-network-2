CC = g++
PROG = sample
CXXFLAGS = -g -O2 -Wall
# CXXFLAGS += -pthread
# LDLIBS += -L/usr/local/lib/ -lmylib
# LDLIBS += -lrt
# LDFLAGS += -pthread

all: $(PROG)
OBJS += $(PROG).o
OBJS += world.o
$(PROG): $(OBJS)

clean:
	rm -f *.o $(PROG)
