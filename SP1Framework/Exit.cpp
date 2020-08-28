#include "Exit.h"

Exit::Exit(COORD _c, MapMaker* map)
{
	c = _c;
	display = 233;
	entity_map = map;
	colour = 0x6B;
	timer = 0;
}

Exit::Exit(int y_pos, int x_pos, MapMaker* map)
{
	c.X = x_pos;
	c.Y = y_pos;
	display = 233;
	entity_map = map;
	colour = 0x6B;
	timer = 0;
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
		return false;
	}
	else {
		return true;
	}
}

void Exit::move(int button_pressed)
{
	//Does not move
}

void Exit::DoEntityTask()
{
	g_bQuitGame = true;
}
