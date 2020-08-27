
#include "Sound.h"

Sound::Sound()
{
	ISoundEngine* engine = createIrrKlangDevice();
}