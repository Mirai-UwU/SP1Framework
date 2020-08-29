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
	bool active;
	
public:
	Sound();
	void BackgroudMusic();
	//Plays back the sound based on which number entered as parameter
	void PlaySound(int i);
	ISoundEngine* Engine();
};

