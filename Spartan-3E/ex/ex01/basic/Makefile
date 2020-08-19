CC = g++
all: sample

sample: sample.o world.o
	$(CC) -o sample sample.o world.o

sample.o: sample.cpp
	$(CC) -c sample.cpp

world.o: world.cpp world.h
	$(CC) -c world.cpp

clean:
	rm -f sample *.o
