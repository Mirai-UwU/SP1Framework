#pragma once
#include "Entity.h"
#include <iostream>

class Rope : public Entity
{
private:

public:
	Rope(int y_pos, int x_pos, MapMaker* map);
	void DoEntityTask(char button);
};