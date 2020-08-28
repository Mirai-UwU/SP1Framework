#pragma once
#include "Entity.h"

extern EGAMESTATES g_eGameState;

class Exit : public Entity
{
private:
public:
	Exit(COORD _c, MapMaker* map);
	Exit(int y_pos, int x_pos, MapMaker* map);
	~Exit();

	bool collide(COORD entity_pos);
	bool collide(int entity_xpos, int entity_ypos);

	void move(int button_pressed);

	void DoEntityTask();

};

