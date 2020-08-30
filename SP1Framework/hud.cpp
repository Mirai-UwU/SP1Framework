#include "HUD.h"


int HUD::lives = 900;
bool HUD::bombheld = false;
bool HUD::teleportheld = false;

HUD::HUD()
{
	flashlight_time = 120;
	updatedlives = 0;
}

HUD::~HUD()
{
}

void HUD::Load(std::string filepath) {

}


void HUD::render()
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

bool HUD::bombhandler()
{
	if ((bombheld == true) && (getPlayerInput() == K_BOMB))
	{//activate ZA WARUDO
		se.Playsound(9);
		bombheld = false;
		return true;
	}
	else {
		return false;
	}
}

int HUD::get_flashlight_time()
{	
	return flashlight_time;
}

void HUD::set_flashlight_time(int i)
{
	flashlight_time = i;
}

void HUD::lose_life()
{
	setLives(getLives() - 300);
}

int HUD::convert_FL_to_percent()
{
	return(((get_flashlight_time() / 120) * 100));	
}

