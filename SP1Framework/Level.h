#pragma once
#include <filesystem>
#include "Entity.h"
#include "Player.h"
#include "guard.h"
#include "MapMaker.h"

class Level
{
private:
	string filepath;


	void Build();
	void FindEntities();
protected:
	
	MapMaker this_map;
	Entity** entity_list;
public:
	Level();
	Level(string filename);
	~Level();
	

};

