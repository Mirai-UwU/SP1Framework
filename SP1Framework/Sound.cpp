
#include "Sound.h"

Sound::Sound()
{
	engine = createIrrKlangDevice();
}

 ISoundEngine* Sound::Engine()
{
	 return engine;
}