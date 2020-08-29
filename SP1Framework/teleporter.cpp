#include "Teleporter.h"

Teleporter::Teleporter(int y_pos, int x_pos, MapMaker* map)
{
	set_xpos(x_pos);
	set_ypos(y_pos);
	set_display('%');
	entity_map = map;
	p = NULL;
    map1 = NULL;
    isActive = true;
}

void Teleporter::DoEntityTask(char input)
{
    getPlayerInput();
        if (input == K_TELEPORTER)
        {
            p->set_xpos(rand() % 100);
            p->set_ypos(rand() % 20);
            while (map1->getFromCoord(p->get_x_pos(), p->get_y_pos()) != ' ')
            {
                p->set_xpos(rand() % 100);
                p->set_ypos(rand() % 20);
            }
        }


}
