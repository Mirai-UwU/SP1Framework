#pragma once
#include "Entity.h"
#include "Framework/console.h"
#include "game.h"
#include "Sound.h"
extern Console g_Console;

class HUD
{
private:

	static int lives;
	static bool bombheld;
	static bool teleportheld;
	int flashlight_time;
	Sound se;
	int updatedlives;
public:
	HUD();
	~HUD();
	void Load(string filepath);

	void render();
	// hud needs to show 1.torchlight time left 2. held bomb 3. held teleporter 4.money left (lives)

	//Get Static Variables
	
	int getLives(); //4. money left +(lives)
	bool holdingbomb(); //2. held bomb
	bool holdingteleporter(); //3 held teleporter
	void setLives(int i);
	void togglebomb();
	void toggleteleporter();
	bool teleporthandler();
	bool bombhandler();
	int get_flashlight_time(); //1.torchlight time left in seconds
	void set_flashlight_time(int i);
	void lose_life();
	int convert_FL_to_percent(); //torchlight time left in percentage
};