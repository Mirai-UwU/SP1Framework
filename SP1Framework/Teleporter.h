#pragma once
#include "Entity.h"
#include "Player.h"
#include "MapMaker.h"

class Teleporter : public Entity
{
private:
	Player* p;
	MapMaker* map1;

public:
	Teleporter(int y_pos, int x_pos, MapMaker* map);
	void DoEntityTask(char input);


};