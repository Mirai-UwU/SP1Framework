#pragma once
#include "Entity.h"
class Exit : public Entity
{
private:
public:
	Exit(COORD _c, MapMaker* map);
	Exit(int y_pos, int x_pos, MapMaker* map);
	~Exit();
};

