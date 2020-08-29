#pragma once
#include "Entity.h"
#include "Framework/console.h"
extern Console g_Console;

class HUD :public Entity
{
private:
	char heldbomb();
	char heldteleport();
public:
	HUD();
	~HUD();
	void Load(string filepath);
	void render();
	// hud needs to show 1.torchlight time left 2. held bomb 3. held teleporter 4.money left (lives)
};