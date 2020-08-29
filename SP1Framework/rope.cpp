#include "Rope.h"
#include "Player.h"
#include "MapMaker.h"
Rope::Rope(int y_pos, int x_pos, MapMaker* map)
{
	set_xpos(x_pos);
	set_ypos(y_pos);
	set_display('&');
	entity_map = map;
	p = NULL;
	isActive = true;
}

void Rope::DoEntityTask(char button)
{
	p->set_xpos(2);
	p->set_ypos(1);
}

