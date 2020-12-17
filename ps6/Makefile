CC = g++
CFLAGS = -g -Wall -Werror -ansi -pedantic -std=c++11
LIBS = -lboost_regex -lboost_date_time

ps6: main.o
	$(CC) $(CFLAGS) -o ps6  main.o $(LIBS)
all: ps6
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
clean:
	 rm *.o ps6
