#include "Flashlight.h"

Flashlight::Flashlight(int y_pos, int x_pos, MapMaker* map)
{
	set_xpos(x_pos);
	set_ypos(y_pos);
	set_display('F');
	entity_map = map;
}
