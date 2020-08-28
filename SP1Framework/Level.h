#pragma once
#include "Entity.h"
#include "Player.h"
#include "guard.h"
#include "MapMaker.h"

extern Console g_Console;

class Level
{
private:
	string filepath;
	
	//Loads everything up
	void Build();
	//Finds and Puts Entities into entity_list
	void FindEntities();
protected:
	
	MapMaker this_map;
	Entity** entity_list;
	int entitycount;
public:
	Level();
	Level(string filename);
	~Level();

	//use if cannot initialise at start
	void Load(string filename); 

	void SetTimers(double t);

	//Returns the Entity you are looking for
	Entity* FindPlayer();
	Entity* FindGuard(); //Finds the first guard in the list
	Entity* FindGuard(int which); //Finds the guard depending on number which

	//Important Functions
	void Update();
	void Render(Console &gConsole);

	//Level functions
	void RenderFog();

};

