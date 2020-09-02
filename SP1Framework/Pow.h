#pragma once
#include "Entity.h"
#include "Player.h"
#include "MapMaker.h"
#include <iostream>


class Power : public Entity
{
private:

public:
	Power(COORD c_pos, MapMaker* map);
	Power(int y_pos, int x_pos, MapMaker* map);
	~Power();

	void move(int button_pressed);
	void DoEntityTask(Entity* player = NULL);

	bool collide(COORD entity_pos);
	bool collide(int entity_xpos, int entity_ypos);
};

