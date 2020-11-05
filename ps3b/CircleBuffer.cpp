// Copyright 2020 Stephanie La

#include  "CircleBuffer.h"
//#include "/home/slaw/ps3a/CircularBuffer.h"
#include <stdint.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

CircularBuffer::CircularBuffer(int capacity) {
    if (capacity < 1) {
        throw std::invalid_argument(
            "CB constructor: capacity must be greater than zero");
    }
    bufferCapacity = capacity;
    bufferSize = 0;
    front = 0;
    buffer = std::unique_ptr<int16_t[]>(new int16_t[capacity]);
}

int CircularBuffer::size() {
    return bufferSize;
}

bool CircularBuffer::isEmpty() {
    return bufferSize == 0;
}

bool CircularBuffer::isFull() {
    return bufferSize == bufferCapacity;
}

void CircularBuffer::enqueue(int16_t x) {
    if (isFull()) {
        throw std::runtime_error("enqueue: can't enqueue to a full ring.");
    }
    // back declaration
    int back = (front + bufferSize) % bufferCapacity;
    buffer[back] = x;
    bufferSize++;
}

int16_t CircularBuffer::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Buffer is empty");
    }
    // save
    int16_t temp = buffer[front];
    front = (front + 1) % bufferCapacity;
    bufferSize--;
    return temp;
}

int16_t CircularBuffer::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Buffer is empty");
    }
    return buffer[front];
    // front is at index front
    // holds the index where the data begins
    // return buffer.at(front);//peek "front" of vector buff also valid
}

void CircularBuffer::emptyBuffer() {
    front = 0;
    bufferSize = 0;
}
