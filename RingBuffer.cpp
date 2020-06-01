#include "RingBuffer.hpp"
#include <vector>
#include <iostream>
#include <stdint.h>
#include <stdexcept>
using namespace std;

RingBuffer::RingBuffer(int capacity)
{
  if(capacity <= 0)
    {
      throw invalid_argument("RB constructor: capacity must be greater than zero");
    }
  buffer.reserve(capacity);
}

int RingBuffer::capacity()
{
  return buffer.capacity();
}

int RingBuffer::size()
{
  return buffer.size();
}

bool RingBuffer::isEmpty()
{
  if(buffer.empty())
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool RingBuffer::isFull()
{
  if(buffer.size() == buffer.capacity())
    {
      return true;
    }
  else
    {
      return false;
    }
}

void RingBuffer::enqueue(int16_t x)
{
  if(this->isFull())
    {
      throw runtime_error("enqueue: can't enqueue to a full ring.");
    }
  buffer.push_back(x);
}

std::int16_t RingBuffer::dequeue()
{
  if(this->isEmpty())
    {
      throw runtime_error("dequeue: can't dequeue from an empty buffer.");
    }
  int16_t front = buffer.front();
  buffer.erase(buffer.begin());
  return front;
}

std::int16_t RingBuffer::peek()
{
  //std::cout << "0" << std::endl;
  if(this->isEmpty())
    {
      throw runtime_error("peek: can't peek from an empty buffer.");
    }
  //std::cout << "1" << std::endl;
  std::int16_t r  = buffer.at(0);
  return r;
}
