#pragma once
#include "Entity.h"
#include <iostream>


class Guard : public Entity
{
protected:

private:

public:
	Guard(COORD c_pos, MapMaker* map);
	Guard(int y_pos, int x_pos, MapMaker* map);
	~Guard();


	void move(int button_pressed);
	void DoEntityTask(Entity* player = NULL);

	bool collide(COORD entity_pos);
	bool collide(int entity_xpos, int entity_ypos);
};
