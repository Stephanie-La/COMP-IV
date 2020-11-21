CC = g++
CFLAGS = -g -Wall -Werror -ansi -pedantic -std=c++11 -O3

ED: EditDistance.o main.o
	$(CC) $(CFLAGS) -o ED EditDistance.o main.o -lsfml-system
all: ED
EditDistance.o: EditDistance.cpp EditDistance.h
	$(CC) $(CFLAGS) -c EditDistance.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
clean:
	 rm *.o ED

