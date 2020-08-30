#include "HUD.h"


int HUD::lives = 900;
bool HUD::bombheld = true;
bool HUD::teleportheld = false;

HUD::HUD()
{
	flashlight_time = 120;
	updatedlives = 0;
	renderhud.Load(".Txt/HUD Template.txt");
}

HUD::~HUD()
{

}

void HUD::Load(std::string filepath) {

}


void HUD::render_HUD()
{
	renderhud.Render(0, 20, 102, 25);
	render_HUD_battery();
	render_HUD_bomb();
	render_HUD_teleport();
	render_HUD_money();
}

void HUD::render_HUD_bomb()
{

	if (holdingbomb() == true)
	{
		g_Console.writeToBuffer(35, 23, "Ready!");
		g_Console.writeToBuffer(32, 24, "Press B to use");
	}
	else
	{
	//	g_Console.writeToBuffer(35, 23, "Ready!");
	//	g_Console.writeToBuffer(32, 24, "Press B to use");
	}
	
}
void HUD::render_HUD_teleport()
{
	if (holdingteleporter() == true)
	{
		g_Console.writeToBuffer(60, 23, "Ready!");
		g_Console.writeToBuffer(57, 24, "Press T to use");
	}
	else {

	}
}

void HUD::render_HUD_money()
{
	g_Console.writeToBuffer(68, 23, "$ " + std::to_string(getLives()));
}

void HUD::render_HUD_battery()
{
	g_Console.writeToBuffer(6, 23, std::to_string(convert_FL_to_percent()) + " % Batterylife");
	g_Console.writeToBuffer(11, 24, "left");
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
	if (bombheld == true) {
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

bool HUD::teleporthandler()
{
	if ((teleportheld == true) && (getPlayerInput() == K_TELEPORTER))
	{//activate teleporter
		se.Playsound(4);
		teleportheld = false;
		return true;
	}
	else {
		return false;
	}
}

bool HUD::bombhandler()
{
	if ((bombheld == true) && (getPlayerInput() == K_BOMB))
	{//activate ZA WARUDO
		se.Playsound(3);
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
	int percentage = (int)(((float)get_flashlight_time() / 120.0) * 100);
	if (percentage > 0){
		return(percentage);
	}
	else {
		return 0;
	}
		
		
}

