#ifndef SOUND_HPP
#define SOUND_HPP

#include <deque>
#include <SFML/Audio.hpp>

class Sound
{
private:
	sf::SoundBuffer buffer;
	std::deque<sf::Sound> instances;
public:
	void load(std::string filename)
	{
		buffer.loadFromFile(filename);
	}

	void update()
	{
		for(int i = 0; i < instances.size(); ++i)
		{
			if(instances[i].getStatus() == sf::Sound::Stopped)
			{
				instances.erase(instances.begin()+i);
				--i;
			}
		}
	}

	void play()
	{
		instances.push_back(sf::Sound(buffer));
		instances.back().play();
	}

	unsigned int count(){return this->instances.size();}
};

#endif // SOUND_HPP