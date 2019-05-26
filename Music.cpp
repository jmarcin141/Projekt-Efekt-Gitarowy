#include "Music.h"



Music::Music() {};

Music::~Music() {};

	void Music::loadSound()
	{
		if (!buf.loadFromFile("E:\\AGH\\Semestr 4\\PO\\Projekty\\Projekt-Efekt-Gitarowy\\imperial_march.wav"))
		{
			std::cout << "not loaded" << std::endl;
			//return -1;
		}
		else { std::cout << "loaded" << std::endl; }
		sound.setBuffer(buf);
	};

	bool Music::getActiveSound()
	{
		sf::Sound::Status active = sound.getStatus();
		if (active == sf::Sound::Status::Playing) //sf::Sound::Status::Playing 
		{
			return true;
		}
		else 
		{
			return false;
		}
	};

	void Music::playSoud()
	{
		 sound.play();
	};

	void Music::stopSound()
	{
		sound.stop();
	};

	void Music::pauseSound()
	{
		sound.pause();
	};

	void Music::loopSound()
	{
		if (sound.getLoop() == true) {
			sound.setLoop(false);
		}
		else { sound.setLoop(true); }
	};

	void Music::rewindSound()
	{
		if (sound.getPlayingOffset() > sf::seconds(5)) {
			sound.setPlayingOffset(sound.getPlayingOffset() - sf::seconds(5));
		}
		else { sound.setPlayingOffset(sf::seconds(0)); }
	};

	void Music::forwardSound()
	{
		sound.setPlayingOffset(sf::seconds(5) + sound.getPlayingOffset());
	};

	void Music::volumePlus()
	{
		//Volume is...(between 0 - 100);
		if (sound.getVolume() <= 100) {
			sound.setVolume(sound.getVolume() + 5);
		}
	};

	void Music::volumeMinus()
	{
		//Volume is...(between 0 - 100);
		if (sound.getVolume() >= 5) {
			sound.setVolume(sound.getVolume() - 5);
		}
	};

	void Music::setVolume(double vol)
	{
		//float _vol = static_cast<float>(vol);
		sound.setVolume(static_cast<float>(vol));
	};


	void Music::speedPlus()
	{
		if (sound.getPitch() <= 2.f) {
			sound.setPitch(sound.getPitch() + 0.2f);
		}
		else if (sound.getPitch() > 2.f && sound.getPitch() < 7.f) {
			sound.setPitch(sound.getPitch() + 1.f);
		}
		else { sound.setPitch(1.f); }
	};

	void Music::speedMinus()
	{
		if (sound.getPitch() <= 2.f && sound.getPitch() > 0.3f) {
			sound.setPitch(sound.getPitch() - 0.2f);
		}
		else if (sound.getPitch() > 2.f && sound.getPitch() < 7.f) {
			sound.setPitch(sound.getPitch() - 1.f);
		}
	};

	sf::Time Music::getTime()
	{
		return sound.getPlayingOffset();
	};

	void Music::loadSamples(std::vector<sf::Int16> &samples, int f)
	{
		buf.loadFromSamples(&samples[0], samples.size(), 1, f);
		sound.setBuffer(buf);
	};


	//std::vector<sf::Int16> Music::soundData()
	//{
	//	std::vector<sf::Int16> _samples;
	//	const sf::Int16 *ptr = buf.getSamples();
	//	for (int i = 0; i++; i < buf.getSampleCount())
	//	{
	//		//_samples.push_back(ptr++);
	//	}
	//	buf.getSamples();
	//}

	//sf::OutputSoundFile Music::soundData()
	//{
	//	return buf.getSamples();
	//}


/*
#include "Music.h"



Music::Music()
{
}


Music::~Music()
{
}


class Music2
{
private:
	sf::SoundBuffer buf;
	sf::Sound sound;

public:
	Music2() {}

	//~Music() {}

	void loadSound()
	{
		if (!buf.loadFromFile("E:\\AGH\\Semestr 4\\PO\\Projekty\\Projekt-Efekt-Gitarowy\\imperial_march.wav"))
		{
			std::cout << "not loaded" << std::endl;
			//return -1;
		}
		else { std::cout << "loaded" << std::endl; }
		sound.setBuffer(buf);
	}

	bool getActiveSound()
	{
		if (sound.getStatus() == sf::Sound::Playing) //sf::Sound::Status::Playing 
		{
			return true;
		}
		else {
			return false;
		}
	}

	void playSoud()
	{
		sound.play();
	}

	void stopSound()
	{
		sound.stop();
	}

	void pauseSound()
	{
		sound.pause();
	}

	void loopSound()
	{
		if (sound.getLoop() == true) {
			sound.setLoop(false);
		}
		else { sound.setLoop(true); }
	}

	void rewindSound()
	{
		if (sound.getPlayingOffset() > sf::seconds(5)) {
			sound.setPlayingOffset(sound.getPlayingOffset() - sf::seconds(5));
		}
		else { sound.setPlayingOffset(sf::seconds(0)); }
	}

	void forwardSound()
	{
		sound.setPlayingOffset(sf::seconds(5) + sound.getPlayingOffset());
	}

	void volumePlus()
	{
		//Volume is...(between 0 - 100);
		if (sound.getVolume() <= 100) {
			sound.setVolume(sound.getVolume() + 5);
		}
	}

	void volumeMinus()
	{
		//Volume is...(between 0 - 100);
		if (sound.getVolume() >= 5) {
			sound.setVolume(sound.getVolume() - 5);
		}
	}

	void setVolume(double vol)
	{
		//float _vol = static_cast<float>(vol);
		sound.setVolume(static_cast<float>(vol));
	}


	void speedPlus()
	{
		if (sound.getPitch() <= 2.f) {
			sound.setPitch(sound.getPitch() + 0.2f);
		}
		else if (sound.getPitch() > 2.f && sound.getPitch() < 7.f) {
			sound.setPitch(sound.getPitch() + 1.f);
		}
		else { sound.setPitch(1.f); }
	}

	void speedMinus()
	{
		if (sound.getPitch() <= 2.f && sound.getPitch() > 0.3f) {
			sound.setPitch(sound.getPitch() - 0.2f);
		}
		else if (sound.getPitch() > 2.f && sound.getPitch() < 7.f) {
			sound.setPitch(sound.getPitch() - 1.f);
		}
	}
};
*/