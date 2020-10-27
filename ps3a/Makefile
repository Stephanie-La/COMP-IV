CC = g++
CFLAGS = -g -w -Wall -Werror -ansi -pedantic -std=c++11

ps3a: CircularBuffer.o test.o
	$(CC) $(CFLAGS) -o ps3a CircularBuffer.o test.o -lboost_unit_test_framework
all: ps3a
CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.cpp
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
clean:
	 rm *.o ps3a

