#pragma once
#include "Entity.h"
#include "Guard.h"
#include "MapMaker.h"
#include <iostream>

class bomb : public Entity
{
private:
	Guard* g;

public:
	bomb(int y_pos, int x_pos, MapMaker* map);
	void DoEntityTask(char input);
};