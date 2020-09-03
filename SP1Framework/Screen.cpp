#include "Screen.h"

Screen::Screen()
{
	origin.X = 0;
	origin.Y = 0;
	start.Load(".Txt/StartScreen.txt");
	death.Load(".Txt/EndScreen.txt");
	win.Load(".Txt/WinScreen.txt");
}

Screen::~Screen()
{
}

void Screen::UpdateStart()
{
	processUserInput();
	if (getPlayerInput() == K_SPACE) {
		g_eGameState = S_LVL00;
	}
}

void Screen::UpdateDeath()
{
	if (getPlayerInput() == K_SPACE) {
		for (int i = 0; i < S_GAMEOVER; i++) {
			lvl[i]->Reset();
		}
		g_eGameState = S_SPLASHSCREEN;
	}
	
}

void Screen::UpdateWin()
{
	UpdateDeath();
}

void Screen::RenderStart()
{	
	start.Render(origin, g_Console.getMaxConsoleSize());
}

void Screen::RenderDeath()
{
	death.Render(origin, g_Console.getMaxConsoleSize());
}

void Screen::RenderWin()
{
	win.Render(origin, g_Console.getMaxConsoleSize());
}
