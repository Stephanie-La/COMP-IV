CC = g++
CFLAGS = -g -w -Wall -Werror -ansi -pedantic
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

NBody: NBody.o main.o
	$(CC) $(CFLAGS) -o NBody NBody.o main.o $(LDLIBS)
all: NBody
NBody.o: NBody.cpp NBody.h
	$(CC) $(CFLAGS) -c NBody.cpp
main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o NBody

