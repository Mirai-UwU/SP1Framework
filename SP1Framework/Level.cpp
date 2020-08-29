#include "Level.h"

void Level::Build()
{
	this_map.Load(filepath);
	entitycount = this_map.getEntityCount();
	entity_list = new Entity* [entitycount];
	FindEntities();
	for (int i = 0; i < entitycount; i++) {
		this_map.setToCoord(entity_list[i]->get_pos(), ' ');
	}
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
			case '@':
				entity_list[count++] = new Player(coord, &this_map);
				break;
			case '!':
				entity_list[count++] = new Guard(coord, &this_map);
				break;
			case '&':
				entity_list[count++] = new Exit(coord, &this_map);
				break;
			default:
				break;
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
void Level::ResetTimers()
{
	for (int i = 0; i < entitycount; ++i) {
		entity_list[i]->reset_timer();
	}
}


Entity* Level::FindPlayer()
{
	for (int i = 0; i < entitycount; i++) {
		if (entity_list[i]->get_display() == '@') {
			return entity_list[i];
		}
		else {
			return NULL;
		}
	}
}

Entity* Level::FindGuard()
{
	for (int i = 0; i < entitycount; i++) {
		if (entity_list[i]->get_display() == (char)2) {
			return entity_list[i];
		}
	}
}



Entity* Level::FindGuard(int which)
{
	if (which < 0 || which >= entitycount) {
		which = entitycount;
	}

	for (int i = which; i < entitycount; i++) {
		if (entity_list[i]->get_display() == (char)2) {
			return entity_list[i];
		}
	}
}

Entity* Level::FindExit()
{
	for (int i = 0; i < entitycount; i++) {
		if (entity_list[i]->get_display() == static_cast<char>(233)) {
			return entity_list[i];
		}
	}
}




void Level::Update()
{
	processUserInput();
	for (int i = 0; i < entitycount; ++i) {
		Entity& ent = *entity_list[i];
		char theEntity = entity_list[i]->get_display();
		switch (theEntity) {
		case (char)2:
			if ((int)ent.get_timer() % 2) {
				if (ent.get_timer() > 0.02) {
					ent.move(rand() % K_COUNT);
					ent.reset_timer();
				}
			}
			break;

		case '@':
			ent.move(getPlayerInput());

			if (FindExit()->get_x_pos() == ent.get_x_pos() && FindExit()->get_y_pos() == ent.get_y_pos() ){
				FindExit()->DoEntityTask();
				ResetTimers();
			}
			break;
		default:
			break;
		}
	}
	

}

void Level::Render()
{
	this_map.Render(0, 0, 102, 20);
	for (int i = 0; i < entitycount; ++i) {
		Entity& ent = *entity_list[i];
		g_Console.writeToBuffer(ent.get_pos(), ent.get_display(), ent.get_colour());	
	}
	RenderFog();
}

void Level::RenderFog()
{
	int ren = 2;
	if (ren == 1)//Flashlight Fog
	{
		for (int x = 0; x < 102; x++) {
			for (int y = 0; y < 20; y++) {
				if (!(x >= FindPlayer()->get_x_pos() - 5 && x <= FindPlayer()->get_x_pos() + 5 && y >= FindPlayer()->get_y_pos() - 3 && y <= FindPlayer()->get_y_pos() + 3)) {
					g_Console.writeToBuffer(x, y, ' ', 0x00);
				}
			}
		}
	}
	if (ren == 2) //No Fog
	{


	}
	if (ren == 3)//No Flashlight fog
	{
		for (int x = 0; x < 102; x++) {
			for (int y = 0; y < 20; y++) {
				if (!(x >= FindPlayer()->get_x_pos() - 1 && x <= FindPlayer()->get_x_pos() + 1 && y >= FindPlayer()->get_y_pos() - 1 && y <= FindPlayer()->get_y_pos() + 1)) {
					g_Console.writeToBuffer(x, y, ' ', 0x00);
				}
			}
		}
	}
}

//void Level::EntityCollision()

