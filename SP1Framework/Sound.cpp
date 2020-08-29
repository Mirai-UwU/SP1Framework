
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

void Sound::Playsound(int i)
{
	/*
	1. Jumpscare when guard collides with player (entity collision)
	2. item pickup when player collides with pickup item (entity collision)
	3. when player uses a bomb (input from user to use item)
	4. when player uses a teleporter (input from user to use item)
	5. when player reaches the level exit (entity collision)
	6. Text to speech to explain story (level class for identifying which level the player is on)
	7. when player moves (player class for movement)
	*/
//	switch(i)
//		case 1:

}

 ISoundEngine* Sound::Engine()
{
	 return engine;
}