#pragma once
#include "Entity.h"
class HUD :public Entity
{
private:
	static int lives;
	static bool bombheld;
	static bool teleportheld;
public:
	HUD();
	~HUD();
	void Load(string filepath);

	//Get Static Variables
	int getLives();
	bool holdingbomb();
	bool holdingteleporter();
	void setLives(int i);
	void togglebomb();
	void toggleteleporter();
};