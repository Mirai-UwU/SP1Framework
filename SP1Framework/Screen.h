#pragma once
#include "MapMaker.h"
#include "Level.h"

extern Level* lvl[S_GAMEOVER];

class Screen
{
private:
	MapMaker start, win, death;
	COORD origin;
public:
	Screen();
	~Screen();

	void UpdateStart();
	void UpdateDeath();
	void UpdateWin();

	void RenderStart();
	void RenderDeath();
	void RenderWin();
};

