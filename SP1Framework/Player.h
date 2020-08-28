#pragma once
#include "Entity.h"
#include <iostream>
#include "Sound.h"




class Player : public Entity
{
private:
	int lives = 3;
	Sound sound;
public:

	Player(COORD c_pos, MapMaker* map);
	Player(int y_pos, int x_pos, MapMaker* map);
	~Player();
	
	int get_lives();
	void move(int button_pressed);
	void DoEntityTask();

	bool collide(COORD entity_pos);
	bool collide(int entity_xpos, int entity_ypos);
};
