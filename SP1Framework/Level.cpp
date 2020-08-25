#include "Level.h"

void Level::Build()
{
	this_map.Load(filepath);
	entity_list = new Entity * [this_map.getEntityCount()];
	FindEntities();
}

void Level::FindEntities()
{
	COORD coord;
	int count = 0;
	for (int row = 0; row < this_map.get_row(); row++) {
		coord.Y = row;
		for (int col = 0; col < this_map.get_col(); col++) {
			coord.X = col;
			char entity = this_map.getFromCoord(coord);
			switch (entity) {
			case 'P':
				entity_list[count++] = new Player(coord, &this_map);
				break;
			case 'G':
				entity_list[count++] = new Guard(coord, &this_map);
				break;

			}
		}
	}
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
