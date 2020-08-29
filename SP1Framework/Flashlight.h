#pragma once
#include "Entity.h"
#include "Player.h"
#include "Level.h"
#include <iostream>

class Flashlight : public Entity
{
private:
	
public:
	Flashlight(int y_pos, int x_pos, MapMaker* map);


	void DoEntityTask();
};