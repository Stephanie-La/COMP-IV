#include  "StringSound.h"
#include  "CircleBuffer.h"

#include <stdint.h>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <random>

StringSound::StringSound(double frequency) {
	//check if frequency is less than zero
	if (frequency < 0) {
		throw std::invalid_argument(
			"frequency must be greater than zero");
	}
	int N = ceil(SAMPLING_RATE / frequency);
	buffer = new CircularBuffer(N); //pass in new object
	for (int i = 0; i < N; i++) {
		buffer->enqueue(0);
	}
	tick_count = 0;
}

StringSound::StringSound(std::vector<int16_t> init) {
	//check if vector is empty
	if (init.empty()) {
		throw std::invalid_argument(
			"vector must be empty");
	}
	buffer = new CircularBuffer(init.size());
	for (int i = 0; i < init.size(); i++) {
		buffer->enqueue(init.at(i));
	}
	tick_count = 0;
}

void StringSound::pluck() {
	// Set up randomness
	std::random_device rd;
	while (!buffer->isEmpty()) { //while not empty, clear buffer
		buffer->dequeue();
	}
	while (!buffer->isFull()) { //while the buffer is not full, fill the buffer with random numbers
		int16_t result = (rd() % (32767 - (-32768) + 1)) + (-32768); //result = rd()%((max- min) + 1) + min;
		buffer->enqueue(result);
	}
}

void StringSound::tic() {

	//lambda
	auto return_enqueue = [&](int16_t x) { return buffer->enqueue(x); };

	int16_t step = ((buffer->dequeue() + buffer->peek()) / 2) * DECAY_FACTOR;
	return_enqueue(step);
	//buffer->enqueue(step);
	tick_count++;
}

int16_t StringSound::sample() {
	return buffer->peek();
}

int StringSound::time() {
	return tick_count;
}

