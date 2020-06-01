#include "GuitarString.hpp"
#include <stdint.h>
#include <vector>
#include <math.h>

const double DECAY_FACTOR = .996;

   GuitarString::GuitarString(double frequency)
   {
     int N = ceil(44100 / frequency);
      buffer = new RingBuffer(N);
     _time = 0;
   }

/*GuitarString::GuitarString(const GuitarString& old_gs)
{
  _time = old_gs._time;
  buffer = new RingBuffer(old_gs.buffer);
}*/

GuitarString::GuitarString(std::vector<std::int16_t> init)
   {
     buffer = new RingBuffer(init.size());
     for(int i = 0; i < init.size(); i++)
       {
	 buffer->enqueue(init[i]);
       }
   }
   void  GuitarString::pluck()
   {

     while(!buffer->isEmpty())
       {
	 buffer->dequeue();
       }
     
     for(int i = 0; i < buffer->capacity(); i++)
       {
	 std::int16_t rand_val = static_cast<std::int16_t>(rand() % 32766);
	 if(static_cast<int>(rand()) % 2)
	   {
	     rand_val *= -1;
	   }
	 
	 buffer->enqueue(rand_val);

       }
       
   }
   void GuitarString::tic()
   {
     std::int16_t first = buffer->dequeue();
     std::int16_t second = buffer->peek();
     buffer->enqueue(((first + second)/2) * DECAY_FACTOR);
     _time++;
   }

   std::int16_t GuitarString::sample()
   {
     return buffer->peek();
   }

   int GuitarString::time()
   {
     return _time;
   }

   GuitarString::~GuitarString()
   {
     delete buffer;
   }


