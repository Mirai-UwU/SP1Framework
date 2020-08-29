#include "HUD.h"


int HUD::lives = 900;
bool HUD::bombheld = false;
bool HUD::teleportheld = false;
HUD::HUD()
{
}

HUD::~HUD()
{
}

void HUD::Load(string filepath)
{
}

int HUD::getLives()
{
	return lives;
}
bool HUD::holdingbomb()
{
	return bombheld;
}

bool HUD::holdingteleporter()
{
	return teleportheld;
}

void HUD::setLives(int i)
{
	lives = i;
}

void HUD::togglebomb()
{
	if (bombheld) {
		bombheld = false;
	}
	else {
		bombheld = true;
	}
}

void HUD::toggleteleporter()
{
	if (teleportheld) {
		teleportheld = false;
	}
	else {
		teleportheld = true;
	}
}