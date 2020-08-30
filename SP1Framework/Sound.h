#pragma once
#include <irrKlang.h>
#include <iostream>
#include <conio.h>

using namespace irrklang;

#pragma comment(lib, "irrKlang.lib")

class Sound
{
private:
	ISoundEngine* engine;
	static bool active;
	
public:
	Sound();
	void BackgroudMusic();
	void Stop_sounds();

	//Plays back the sound based on which number entered as parameter
	void Playsound(int i);
	ISoundEngine* Engine();
};

