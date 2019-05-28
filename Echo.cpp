#include "Echo.h"



Echo::Echo()
{
	//Music::getData();
}


Echo::~Echo()
{
}

void Echo::setEcho(Music &music)
{
	// echo efekt
	music.loadSound();
	std::vector<sf::Int16> Dsamples;
	Dsamples = music.getSamples();

	int start = 0;
	int delay = 3000;
	//int length = 500000;
	sf::Uint64 length = music.getLength();
	float echo_force = 1.5;


	std::vector<sf::Int16> delayedSamples;
	for (start; start < length; start++)
	{
		delayedSamples.push_back(Dsamples.at(start));
		//Dsamples.at(i + delay) = Dsamples.at(i) + delayedSamples.at(i);
	}

	for (int i = 0; i < delayedSamples.size() - delay; i++)
	{
		//delayedSamples.push_back(Dsamples.at(i));
		Dsamples.at(i + delay) = Dsamples.at(i + delay) + echo_force * delayedSamples.at(i);
	}
	music.loadSamples(Dsamples, fs);
};
