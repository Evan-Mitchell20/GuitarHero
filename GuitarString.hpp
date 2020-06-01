#include "RingBuffer.hpp"
#include <stdint.h>
#include <vector>

class GuitarString
{
public:
  GuitarString(double frequency);
  GuitarString(std::vector<std::int16_t> init);
  void pluck();
  void tic();
  std::int16_t sample();
  int time();
  ~GuitarString();
  //GuitarString(const GuitarString& old_gs);
private:
  RingBuffer* buffer;
  int _time;
};
