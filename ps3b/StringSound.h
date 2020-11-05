#ifndef STRINGSOUND_H
#define STRINGSOUND_H

#include  "CircleBuffer.h"

#include <stdint.h>
#include <iostream>
#include <vector>
#include <memory>

const int SAMPLING_RATE = 44100;
const double DECAY_FACTOR = 0.996;

class StringSound {
public:
	StringSound(double frequency);				// create a guitar string sound of the 
												// given frequency using a sampling rate
												// of 44,100
	StringSound(std::vector<int16_t> init);		// create a guitar string with
												// size and initial values are given by
												// the vector
	void pluck();								// pluck the guitar string by replacing
												// the buffer with random values,
												// representing white noise
	void tic();									// advance the simulation one time step
	int16_t sample();							// return the current sample
	int time();									// return number of times tic was called 
												// so far
private:
	CircularBuffer* buffer;
	int tick_count;
};
#endif //STRINGSOUND_H
