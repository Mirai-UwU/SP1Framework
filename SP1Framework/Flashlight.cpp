#include "Flashlight.h"




Flashlight::Flashlight(int y_pos, int x_pos, MapMaker* map)
{
	set_xpos(x_pos);
	set_ypos(y_pos);
	set_display('F');
	entity_map = map;
}

void Flashlight::DoEntityTask()
{
	set_timer(120);
	{
		if (timer <= 0)
		{
			for (int x = 0; x < 102; x++) {
				for (int y = 0; y < 20; y++) {
					if (!(x >= p->get_x_pos() - 5 && x <= p->get_x_pos() + 5 && y >= p->get_y_pos() - 3 && y <= p->get_y_pos() + 3)) {
						g_Console.writeToBuffer(x, y, ' ', 0x00);
					}
				}
			}
			
		}
	}
	

}
