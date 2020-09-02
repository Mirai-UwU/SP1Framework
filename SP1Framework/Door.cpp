#include "Door.h"


Door::Door(COORD c_pos, MapMaker* map)
{
    set_pos(c_pos);
    set_display((char)93);
    entity_map = map;
    colour = 0x2;
    timer = 0;
    isActive = true;
}


Door::Door(int y_pos, int x_pos, MapMaker* map)
{
    set_xpos(x_pos);
    set_ypos(y_pos);
    set_display((char)93);
    entity_map = map;
    colour = 0x2;
    timer = 0;
    isActive = true;
}

Door::~Door()
{
}


void Door::move(int button_pressed)
{
}

void Door::DoEntityTask(Entity* player)
{
    hud.Door_open();
    toggle();
}

bool Door::collide(COORD entity_pos)
{
    return collide(entity_pos.X, entity_pos.Y);;
}

bool Door::collide(int entity_xpos, int entity_ypos)
{
    COORD pos;
    pos.X = entity_xpos;
    pos.Y = entity_ypos;
    if (entity_map->getMapArray()[entity_ypos][entity_xpos] == ' ') {
        return false;
    }
    else {
        return true;
    }
}