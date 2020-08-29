
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

void Sound::PlaySound(int i)
{
	switch (i) {
		case 1:
			engine->play2D("");
			break;
		case 2:
			engine->play2D("");
			break;
		case 3:
			engine->play2D("");
			break;
		case 4:
			engine->play2D("");
			break;
		case 5:
			engine->play2D("");
			break;

	}
	
}


 ISoundEngine* Sound::Engine()
{
	 return engine;
}