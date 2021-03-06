#include "GameLevel.h"


GameLevel::GameLevel() : filename("")
{
	map_entities = NULL;
}

GameLevel::GameLevel(string filepath)
{
	filename = filepath;
	
}

GameLevel::~GameLevel()
{
	delete[] map_entities;
	filename = "";
	map_entities = NULL;
}

void GameLevel::CreateEntities()
{
	
	map_entities = new Entity* [this_map.getEntityCount()];
}


void GameLevel::Load()
{
	this_map.Load(filename);
}
