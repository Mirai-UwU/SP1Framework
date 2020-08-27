#pragma once
#include "Entity.h"
#include <iostream>

class bomb : public Entity
{
private:

public:
	bomb(int y_pos, int x_pos, MapMaker* map);
};