#pragma once
#include "Entity.h"
#include "MapMaker.h"
#include "Player.h"
#include <iostream>


class Door : public Entity
{
private:

public:
	Door(COORD c_pos, MapMaker* map);
	Door(int y_pos, int x_pos, MapMaker* map);
	~Door();


	void move(int button_pressed);
	void DoEntityTask(Entity* player = NULL);

	bool collide(COORD entity_pos);
	bool collide(int entity_xpos, int entity_ypos);
};  

