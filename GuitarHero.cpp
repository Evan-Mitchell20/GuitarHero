#include <exception>
#include <stdexcept>
#include <stdint.h>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <map>
#include <string>
#include <math.h>

#include "GuitarString.hpp"

const double CONC_A = 220.0;
const double SAMPLES_PER_SECOND = 44100;

std::vector<std::int16_t> make_samples(GuitarString& g)
{
  std::vector<std::int16_t> samples;
  g.pluck();
  for(int i = 0; i <  44100 * 8; i++)
    {
      g.tic();
      samples.push_back(g.sample());
    }
  return samples;
}

int main()
{
  srand(time(NULL));
  
  sf::RenderWindow window(sf::VideoMode(300, 200), "Guitar Hero");
  sf::Event event;

  std::string key_list("q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ");
  std::map <char, double> key_frequency_pairs;
  std::map <char, sf::Sound> key_sound_pairs;
  
  for(int i = 0; i < 37; i++)
    {
      key_frequency_pairs.insert(pair<char, double>(key_list[i], (CONC_A * 2) * pow(2, (i - 24) / 12)));
    }
    
   std::vector<std::int16_t> samples;

   vector<sf::SoundBuffer*> buffer_ps;
   
   for(map<char, double>::iterator it = key_frequency_pairs.begin(); it != key_frequency_pairs.end(); ++it)
    {
      GuitarString gs  = GuitarString(it->second);
      sf::Sound sound;
      sf::SoundBuffer sbuffer;
      samples = make_samples(gs);
      if(!sbuffer.loadFromSamples(&samples[0], samples.size(), 2, SAMPLES_PER_SECOND))
	 throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
      buffer_ps.push_back(new sf::SoundBuffer(sbuffer));
      sound.setBuffer(*(buffer_ps.back()));
      key_sound_pairs.insert(pair<char, sf::Sound>(it->first, sound));
    }

    while (window.isOpen())
      {
    while (window.pollEvent(event))
      {
      switch (event.type)
	{
	case sf::Event::Closed:
	  {
	    window.close();
	    break;
	  }
	case sf::Event::TextEntered:
	  {
		for(int i = 0; i < 37; i++)
		  {
		    if(static_cast<char>(event.text.unicode) == key_list[i])
		      {
			key_sound_pairs.lower_bound(static_cast<char>(event.text.unicode))->second.play();
		      }
		  }
	      
	    break;
	  }

	   default:
           break;
     
      }

      window.clear();
      window.display();
    }
  }
    
  return 1;
  }



