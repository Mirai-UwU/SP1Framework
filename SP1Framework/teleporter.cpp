#include "Teleporter.h"

Teleporter::Teleporter(COORD pos, MapMaker* map)
{
    set_xpos(pos.X);
    set_ypos(pos.Y);
    set_display((char)4);
    colour = 0x8A;
    entity_map = map;
    timer = 0;
    isActive = true;
}

Teleporter::Teleporter(int y_pos, int x_pos, MapMaker* map)
{
	set_xpos(x_pos);
	set_ypos(y_pos);
	set_display((char)4);
    colour = 0x8A;
	entity_map = map;
    timer = 0;
    isActive = true;
}

bool Teleporter::collide(COORD entity_pos)
{
    return collide(entity_pos.X, entity_pos.Y);;
}

bool Teleporter::collide(int entity_xpos, int entity_ypos)
{
    if (get_x_pos() == entity_xpos && get_y_pos() == entity_ypos) {

        return true;
    }
    return false;
}

void Teleporter::move(int button_pressed)
{

}

void Teleporter::DoEntityTask(Entity* player)
{
    if (!hud.holdingteleporter()) {
        toggle();
        hud.toggleteleporter();
    }

}
