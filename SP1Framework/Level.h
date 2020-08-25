#pragma once
#include "Entity.h"
#include "Player.h"
#include "guard.h"
#include "MapMaker.h"

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
public:
	Level();
	Level(string filename);
	~Level();

	//use if cannot initialise at start
	void Load(string filename); 

	void Render(Console &gConsole);

};

