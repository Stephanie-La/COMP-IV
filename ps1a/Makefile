CC = g++
CFLAGS = -g -w -Wall -Werror -ansi -pedantic

ps1a: FibLFSR.o test.o
	$(CC) $(CFLAGS) -o ps1a FibLFSR.o test.o -lboost_unit_test_framework
all: ps1a
FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
clean:
	rm ps1a

