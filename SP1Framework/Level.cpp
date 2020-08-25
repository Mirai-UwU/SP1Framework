#include "Level.h"

void Level::Build()
{
	this_map.Load(filepath);
	entity_list = new Entity * [this_map.getEntityCount()];
	FindEntities();
}

void Level::FindEntities()
{
}

Level::Level()
{
	filepath = ".Txt/Map Template.txt";
	entity_list = NULL;
}

Level::Level(string filename)
{
	ifstream f(filename);
	if (f.good()) {
		filepath = filename;
	}
	else {
		filepath = ".Txt/Map Template.txt";
	}
}

Level::~Level()
{
	delete[] entity_list;
}
