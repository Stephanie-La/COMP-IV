CC = g++
CFLAGS = -g -w -Wall -Werror -ansi -pedantic -std=c++11
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
KSGuitarSim: CircleBuffer.o StringSound.o KSGuitarSim.o
	$(CC) $(CFLAGS) -o KSGuitarSim CircleBuffer.o StringSound.o KSGuitarSim.o $(LIBS)
all: KSGuitarSim
CircularBuffer.o: CircleBufferBuffer.cpp CircleBuffer.h
	$(CC) $(CFLAGS) -c CircleBuffer.cpp
StringSound.o: StringSound.cpp StringSound.h
	$(CC) $(CFLAGS) -c StringSound.cpp
KSGuitarSim.o: KSGuitarSim.cpp
	$(CC) $(CFLAGS) -c KSGuitarSim.cpp
clean:
	 rm *.o KSGuitarSim
