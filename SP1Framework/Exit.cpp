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
