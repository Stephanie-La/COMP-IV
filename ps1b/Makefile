CC = g++
CFLAGS = -g -w -Wall -Werror -ansi -pedantic
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

Photomagic: LFSR.o PhotoMagic.o
	$(CC) $(CFLAGS) -o Photomagic LFSR.o PhotoMagic.o $(LDLIBS)
all: Photomagic
FibLFSR.o: LFSR.cpp LFSR.h
	$(CC) $(CFLAGS) -c LFSR.cpp
PhotoMagic.o: PhotoMagic.cpp 
	$(CC) $(CFLAGS) -c PhotoMagic.cpp

clean:
	rm *.o Photomagic

