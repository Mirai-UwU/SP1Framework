#pragma once
#include "Entity.h"
#include "Framework/console.h"
#include "game.h"
#include "Sound.h"
extern Console g_Console;

class HUD :public Entity
{
private:

	static int lives;
	static bool bombheld;
	static bool teleportheld;
	int flashlight_time;
	Sound se;
public:
	HUD();
	~HUD();
	void Load(string filepath);

	void render();
	// hud needs to show 1.torchlight time left 2. held bomb 3. held teleporter 4.money left (lives)

	//Get Static Variables
	int getLives();
	bool holdingbomb();
	bool holdingteleporter();
	void setLives(int i);
	void togglebomb();
	void toggleteleporter();
	bool bombhandler();
	int get_flashlight_time();
	void set_flashlifht_time(int i);
};