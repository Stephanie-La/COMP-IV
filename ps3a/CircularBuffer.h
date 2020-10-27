// Copyright 2020 Stephanie La

//#ifndef CIRCULARBUFFER_H // NOLINT
//#define CIRCULARBUFFER_H // NOLINT
#ifndef _HOME_SLAW_PS3A_CIRCULARBUFFER_H_
#define _HOME_SLAW_PS3A_CIRCULARBUFFER_H_
#include <stdint.h>
#include <iostream>
#include <vector>
#include <memory>

class CircularBuffer {
 public:
// create an empty ring buffer, with given max
explicit CircularBuffer(int capacity);
  // capacity
// return number of items currently in the buffer
  int size();
// is the buffer empty (size equals zero)?
  bool isEmpty();
// is the buffer full (size equals capacity)?
  bool isFull();
// add item x to the end
  void enqueue(int16_t x);
// delete and return item from the front
  int16_t dequeue();
// return (but do not delete) item from the front
  int16_t peek();

 private:
  std::unique_ptr<int16_t[]>buffer;
  int bufferSize;
  int bufferCapacity;
  int front;
};
#endif  // _HOME_SLAW_PS3A_CIRCULARBUFFER_H_
