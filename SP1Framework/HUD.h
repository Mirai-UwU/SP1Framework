#pragma once
#include <string>
#include "Framework/console.h"
#include "MapMaker.h"
#include "game.h"
#include "Sound.h"
#include "Level.h"



extern Console g_Console;

class HUD
{
private:

	static int lives;
	static bool bombheld;
	static bool teleportheld;
	static bool f;
	int flashlight_time;
	MapMaker renderhud;
	Sound se;
	int updatedlives;

public:
	HUD();
	~HUD();
	void Load(std::string filepath);

	void render_HUD();
	void render_HUD_bomb();
	void render_HUD_teleport();
	void render_HUD_money();
	void render_HUD_battery();
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
	void Door_open();
	void powerUp();
};