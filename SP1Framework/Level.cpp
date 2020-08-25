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
			default:
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
		Build();
	}
	else {
		filepath = ".Txt/Map Template.txt";
		entity_list = NULL;
	}

}

Level::~Level()
{
	for (int i = 0; i < this_map.getEntityCount(); ++i) {
		delete entity_list[i];
	}
	delete[] entity_list;
}

void Level::Load(string filename)
{
	ifstream f(filename);
	if (f.good()) {
		filepath = filename;
		Build();
	}
	else {
		filepath = ".Txt/Map Template.txt";
		entity_list = NULL;
	}
}

void Level::Render(Console &gConsole)
{
	this_map.Render(0, 0, 100, 20, gConsole);
	for (int i = 0; i < this_map.getEntityCount(); ++i) {
		gConsole.writeToBuffer(entity_list[i]->get_pos(), entity_list[i]->get_display(), 0x0c);
	}
}
