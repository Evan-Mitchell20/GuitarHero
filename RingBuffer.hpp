#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;

//RingBuffer class
class RingBuffer
{
public:
  RingBuffer(int capacity);
  int capacity();
  int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
private:
  vector<int16_t> buffer;
};
#endif
