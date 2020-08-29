#pragma once
#include "Entity.h"
#include "Player.h"
#include <iostream>

class Rope : public Entity
{
private:
	Player* p;

public:
	Rope(int y_pos, int x_pos, MapMaker* map);
	void DoEntityTask(char button);
};