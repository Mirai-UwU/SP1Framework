#include "Exit.h"


Exit::Exit(COORD _c, MapMaker* map)
{
	c = _c;
	set_display(static_cast<char>(233));
	entity_map = map;
	colour = 0x6B;
	timer = 0;
	isActive = true;
}

Exit::Exit(int y_pos, int x_pos, MapMaker* map)
{
	c.X = x_pos;
	c.Y = y_pos;
	set_display(static_cast<char>(233));
	entity_map = map;
	colour = 0x6B;
	timer = 0;
	isActive = true;
}

Exit::~Exit()
{
}

bool Exit::collide(COORD entity_pos)
{
	return collide(entity_pos.X,entity_pos.Y);
}

bool Exit::collide(int entity_xpos, int entity_ypos)
{
	if (this->get_x_pos() == entity_xpos && this->get_y_pos() == entity_ypos) {
		return true;
	}
	else {
		return false;
	}
}

void Exit::move(int button_pressed)
{
	//Does not move
}

void Exit::DoEntityTask(Entity* player)
{
	se.Playsound(5);
	hud.set_flashlight_time(12);
	g_eGameState = (EGAMESTATES)((int)(g_eGameState) + 1); //Increment Gamestate by 1
}
