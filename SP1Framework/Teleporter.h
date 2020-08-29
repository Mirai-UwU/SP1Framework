#pragma once
#include "Entity.h"
#include "Player.h"
#include "MapMaker.h"

class Teleporter : public Entity
{
private:


public:
	Teleporter(COORD pos, MapMaker* map);
	Teleporter(int y_pos, int x_pos, MapMaker* map);
	bool collide(COORD entity_pos);
	bool collide(int entity_xpos, int entity_ypos);
	void move(int button_pressed);


	void DoEntityTask(Entity* player = NULL);


};