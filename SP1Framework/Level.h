#pragma once
#include "Entity.h"
#include "Player.h"
#include "Exit.h"
#include "guard.h"
#include "MapMaker.h"
#include "Sound.h"

extern Console g_Console;
extern double g_dElapsedTime;

class Level
{
private:
	string filepath;
	//Loads everything up
	void Build();
	//Finds and Puts Entities into entity_list
	void FindEntities();
	COORD* initial_pos;

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
	void ResetTimers();

	//Returns the Entity you are looking for
	Entity* FindPlayer();
	Entity* FindGuard(); //Finds the first guard in the list
	Entity* FindGuard(int which); //Finds the guard depending on number which
	Entity* FindExit();

	//Sound Function
	void Playsound();

	//Important Functions
	void Update();
	void Render();
	void Reset();

	//Level functions
	void RenderFog();
	void EntityCollision(Entity& entityptr);

};

