#include "Pow.h"
#include "HUD.h"
#include "Level.h"
#include "Entity.h"

Level lvl;

Power::Power(COORD c_pos, MapMaker* map)
{
    set_pos(c_pos);
    set_display((char)168);
    entity_map = map;
    colour = 0x2b;
    timer = 0;
    isActive = true;
    isApower = true;
}


Power::Power(int y_pos, int x_pos, MapMaker* map)
{
    set_xpos(x_pos);
    set_ypos(y_pos);
    set_display((char)168);
    entity_map = map;
    colour = 0x2b;
    timer = 0;
    isActive = true;
    isApower = true;
}

Power::~Power()
{
}


void Power::move(int button_pressed)
{
}

void Power::DoEntityTask(Entity* player)
{
    hud.set_powertime(6);
    toggle2();
}

bool Power::collide(COORD entity_pos)
{
    return collide(entity_pos.X, entity_pos.Y);;
}

bool Power::collide(int entity_xpos, int entity_ypos)
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
