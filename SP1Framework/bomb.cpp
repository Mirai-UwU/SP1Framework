#include "bomb.h"


Bomb::Bomb(COORD pos, MapMaker* map)
{
	set_xpos(pos.X);
	set_ypos(pos.Y);
	set_display((char)235);
	colour = 0xb0;
	entity_map = map;
	timer = 0;
	isActive = true;
}

Bomb::Bomb(int y_pos, int x_pos, MapMaker* map)
{
	set_xpos(x_pos);
	set_ypos(y_pos);
	set_display((char)235);
	colour = 0x70;
	entity_map = map;
	timer = 0;
	isActive = true;
}

bool Bomb::collide(COORD entity_pos)
{
	return collide(entity_pos.X, entity_pos.Y);;
}

bool Bomb::collide(int entity_xpos, int entity_ypos)
{
	if (get_x_pos() == entity_xpos && get_y_pos() == entity_ypos) {

		return true;
	}
	return false;
}

void Bomb::move(int button_pressed)
{
	
}

void Bomb::DoEntityTask(Entity* player)
{
		if (getPlayerInput() == K_BOMB && !active())
		{
			player->toggle();
		}
}
