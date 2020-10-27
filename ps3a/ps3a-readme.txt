/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Stephanie La


Hours to complete assignment:5

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
I have created functions to enqueue and dequeue a circular buffer with
a fixed size. The ability to peek into the queue and check if the queue
is empty or full is also implemented.




/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
To keep track of size and the index of the circular buffer, I used a 
front index and bufferSize variable. For my CircularBuffer class, I wrote:
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




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
For functions like the cosntructor, enqueue, and dequeue, I wrote for 
example:
 if (capacity < 1) {
        throw std::invalid_argument(
            "CB constructor: capacity must be greater than zero");
    }

I would throw an invalid argument when the if statement would not be true. 
It would exit the function wihtout creating the cosntructor.


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed the assignment successfully. I knew they worked since I 
tested them with unit tests.

/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
They do pass each unit tests. I know since they do not give me a fatal 
error for the test function.




/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
Ringbuffer has a fixed size, meaning it will not allocate size from it's 
original construct. Enqueue and dequeue are linear oeprations, meaning they
do not cost a lot of memory to find or search through the queue and save 
the value.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Youtube, Stack overflow, and cppLint guide.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
When attempting to use cpplint on my 3 files, I had to comment out 
#include  "CircularBuffer.h" because cpplint was complaining that it was 
the wrong header file. It instead prompted me to use the directory path on my machine.
#ifndef _HOME_SLAW_PS3A_CIRCULARBUFFER_H_ and #define _HOME_SLAW_PS3A_CIRCULAR
-BUFFER_H_ instead of //#ifndef CIRCULARBUFFER_H // NOLINT and //#define 
CIRCULARBUFFER_H // NOLINT.It wa If graders want to run and test, 
they will have to change the guards and uncomment the CircularBuffer.h 
to use and change the #endif //CircularBuffer.h too.



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
cpplint was frustrating to deal with. The error involving whitespaces and
changing tabs to spaces was not necessary. 
