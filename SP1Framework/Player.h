#pragma once
#include "Entity.h"
#include <iostream>


class Player : public Entity
{
private:
	int lives = 3;

public:

	Player(COORD c_pos, MapMaker* map);
	Player(int y_pos, int x_pos, MapMaker* map);
	~Player();
	
	int get_lives();
	void move(int button_pressed);

	bool collide(COORD entity_pos);
	bool collide(int entity_xpos, int entity_ypos);
};
