
#include "Sound.h"

Sound::Sound()
{
	engine = createIrrKlangDevice();
	active = false;
}

void Sound::BackgroudMusic()
{
		if (active == false)
		{
			engine->play2D("background_music.wav", true);
			active = true;
		}
		else{}

	
}


 ISoundEngine* Sound::Engine()
{
	 return engine;
}