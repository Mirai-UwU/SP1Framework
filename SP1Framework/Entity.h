#pragma once
#include "Framework/console.h"
#include "game.h"
#include "MapMaker.h"
#include "Sound.h"
#include <windows.h>

extern EGAMESTATES g_eGameState;
extern double g_dElapsedTime;
class Entity
{
protected:
	COORD c;
	MapMaker* entity_map;
	WORD colour;
	char display;
	double timer;
	bool isActive;
	Sound se;
public:


	Entity();
	Entity(COORD _c, char _display, MapMaker* map);
	Entity(int _y_pos, int _x_pos, char _display, MapMaker* map);
	~Entity();
	
	//Get COORD or X and Y pos separately
	COORD get_pos();
	int get_x_pos();
	int get_y_pos();
	
	//Set COORD or X and Y pos separately
	void set_pos(COORD _c);
	void set_ypos(int _y_pos);
	void set_xpos(int _x_pos);

	//Get/Set Entity's symbol
	char get_display();
	void set_display(char _display);

	//Get/Set Entity's colour
	WORD get_colour();
	void set_colour(WORD color);

	//Get/Set isActive
	bool active();
	void toggle();

	//Get/Set Entity's timer
	double get_timer();
	void set_timer(double t);
	void reset_timer();

	//check if collision with COORD.
	//does collision code.
	virtual bool collide(COORD entity_pos) = 0;
	virtual bool collide(int entity_xpos, int entity_ypos) = 0;

	//Move based on enum EKEYS button pressed
	virtual void move(int button_pressed) = 0;

	//Runs any special entity specific event
	virtual void DoEntityTask() = 0;

	//Allow the entity to move
	void move_up(int distance);
	void move_down(int distance);
	void move_left(int distance);
	void move_right(int distance);

};
