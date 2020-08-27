#include "Level.h"

void Level::Build()
{
	this_map.Load(filepath);
	entitycount = this_map.getEntityCount();
	entity_list = new Entity* [entitycount];
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


			/*switch (entity) {
			case 'P':
				entity_list[count] = new Player(coord, &this_map);
				count += 1;
				break;
			case 'G':
				entity_list[count] = new Guard(coord, &this_map);
				count += 1;
				break;
			default:
				break;
			}*/

			if (entity == 'P') {
				entity_list[count++] = new Player(coord, &this_map);
				this_map.setToCoord(coord, ' ');
			} 
			if (entity == 'G') {
				entity_list[count++] = new Guard(coord, &this_map);
				this_map.setToCoord(coord, ' ');
			}
		}
	}
	
}


Level::Level()
{
	entitycount = 0;
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
	for (int i = 0; i < entitycount; ++i) {
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

void Level::SetTimers(double t)
{
	for (int i = 0; i < entitycount; ++i) {
		entity_list[i]->set_timer(t);
	}
}

void Level::Update()
{
	processUserInput();
	for (int i = 0; i < entitycount; ++i) {
		char theEntity = entity_list[i]->get_display();
		switch (theEntity) {
		case (char)2:
			if (entity_list[i]->get_timer() > 0) {
				entity_list[i]->move(rand() % K_COUNT);
				entity_list[i]->set_timer(0);
			}
			break;

		case '@':
			entity_list[i]->move(getPlayerInput());
			break;
		default:
			break;
		}
	}
	

}

void Level::Render(Console &gConsole)
{
	this_map.Render(0, 0, 100, 20, gConsole);
	for (int i = 0; i < entitycount; ++i) {
		Entity& ent = *entity_list[i];
		gConsole.writeToBuffer(ent.get_pos(), ent.get_display(), ent.get_colour());	
	}
}