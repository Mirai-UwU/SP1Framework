#pragma once
#include "Entity.h"
#include "MapMaker.h"
#include "Player.h"
#include <iostream>


class Pow : public Entity
{
private:

public:
	Pow(COORD c_pos, MapMaker* map);
	Pow(int y_pos, int x_pos, MapMaker* map);
	~Pow();

	void move(int button_pressed);
	void DoEntityTask(Entity* player = NULL);

	bool collide(COORD entity_pos);
	bool collide(int entity_xpos, int entity_ypos);
};

