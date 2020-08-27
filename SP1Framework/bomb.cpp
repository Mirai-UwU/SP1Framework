#include "bomb.h"
#include "MapMaker.h"

bomb::bomb(int y_pos, int x_pos, MapMaker* map)
{
	set_xpos(x_pos);
	set_ypos(y_pos);
	set_display('B');
	entity_map = map;
}
