#include "bomb.h"


bomb::bomb(int y_pos, int x_pos, MapMaker* map)
{
	set_xpos(x_pos);
	set_ypos(y_pos);
	set_display('B');
	entity_map = map;
}

void bomb::DoEntityTask(char input)
{
	getPlayerInput();
		if (input == K_BOMB)
		{
			g->set_xpos(2000);
			g->set_ypos(2000);
		}
}
