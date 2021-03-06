
#include "Sound.h"

bool Sound::active = false;

Sound::Sound()
{
	engine = createIrrKlangDevice();
	
}

Sound::~Sound()
{
	engine->drop();
}

void Sound::BackgroudMusic()
{
		if (active == false)
		{
			engine->play2D("Sounds/background_music.mp3", true);
			active = true;
		}
		else{}

	
}


void Sound::Stop_sounds()
{
	if (active == true) {
		engine->removeSoundSource("Sounds/background_music.mp3");
		active = false;
	}
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
	switch (i)
	{
		case 1: engine->play2D("Sounds/whereisit.wav");
			break;
		case 2: engine->play2D("Sounds/itemget.wav");
			break;
		case 3: engine->play2D("Sounds/use_bomb.wav");
			break;
		case 4: engine->play2D("Sounds/use_teleport.wav");
			break;
		case 5: engine->play2D("Sounds/exit.wav");
			break;
		case 6: engine->play2D("");
			break;
		case 7: engine->play2D("Sounds/footstep.mp3");
			break;
		case 8: engine->play2D("Sounds/power_down.wav");
			break;
		//case 9: engine->play2D("Sounds/ZA_WARUDO.wav")
		//	break;
	}
		
}

 ISoundEngine* Sound::Engine()
{
	 return engine;
}