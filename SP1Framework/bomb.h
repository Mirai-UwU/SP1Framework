#pragma once
#include "Entity.h"
#include "Guard.h"
#include "MapMaker.h"
#include <iostream>

class Bomb : public Entity
{
private:

public:
	Bomb(COORD pos, MapMaker* map);
	Bomb(int y_pos, int x_pos, MapMaker* map);
	using Entity::collide;
	bool collide(COORD entity_pos);
	bool collide(int entity_xpos, int entity_ypos);
	void move(int button_pressed);
	void DoEntityTask(Entity* player = NULL);
};