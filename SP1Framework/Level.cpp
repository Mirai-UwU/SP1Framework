#include "Level.h"




void Level::Build()
{
	this_map.Load(filepath);
	entitycount = this_map.getEntityCount();
	entity_list = new Entity* [entitycount];
	initial_pos = new COORD[entitycount];
	FindEntities();
	for (int i = 0; i < entitycount; i++) {
		this_map.setToCoord(entity_list[i]->get_pos(), ' ');
		initial_pos[i] = entity_list[i]->get_pos();
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
			case '%':
				entity_list[count++] = new Bomb(coord, &this_map);
				break;
			case '$':
				entity_list[count++] = new Teleporter(coord, &this_map);
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
	render_fogstate = FogState::STATE_MAX;
	entity_list = NULL;
	initial_pos = NULL;
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
		initial_pos = NULL;
	}
	render_fogstate = FogState::STATE_MAX;

}

Level::~Level()
{
	for (int i = 0; i < entitycount; ++i) {
		delete entity_list[i];
	}
	delete[] entity_list;
	delete[] initial_pos;
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





void Level::setFog(int i)
{
	render_fogstate = static_cast<FogState>(i % (int)FogState::STATE_COUNT);
}


Entity* Level::FindPlayer()
{
	for (int i = 0; i < entitycount; i++) {
		if (entity_list[i]->get_display() == '@') {
			return entity_list[i];
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
		COORD oldpos = ent.get_pos();
		
		if (ent.active()) {
			char theEntity = entity_list[i]->get_display();
			switch (theEntity) {
			case (char)2:
				if ((int)g_dElapsedTime % 2 ) {
					if (ent.get_timer() > 0.02) {
						ent.move(rand() % K_COUNT);
						ent.reset_timer();
					}
					
				}
				break;

			case '@':
				
					ent.move(getPlayerInput());
				
					if (ent.get_timer() > 0.1)
					{
						if ((oldpos.X != ent.get_x_pos()) || (oldpos.Y != ent.get_y_pos()))
						{
							se.Playsound(7);
							ent.reset_timer();
						}
						
					}

					if (hud.get_flashlight_time() > 3) {
						setFog(1);
					}

				break;
			default:
				break;
			}
			EntityCollision(ent);
		}
	}
	if (hud.getLives() < 0) {
		

	}
	

}



void Level::Render()
{
	this_map.Render(0, 0, 102, 20);
	for (int i = 0; i < entitycount; ++i) {
		Entity& ent = *entity_list[i];
		if (ent.active()) {
			g_Console.writeToBuffer(ent.get_pos(), ent.get_display(), ent.get_colour());
		}
	}
	RenderFog();
}

void Level::Reset()
{
	for (int i = 0; i < entitycount; i++) {
		Entity& ent = *entity_list[i];
		ent.set_pos(initial_pos[i]);
		ResetTimers();
	}
}

void Level::RenderRadius(int x_rad, int y_rad)
{
	for (int x = 0; x < 102; x++) {
		for (int y = 0; y < 20; y++) {
			if (!(x >= FindPlayer()->get_x_pos() - x_rad && x <= FindPlayer()->get_x_pos() + x_rad && y >= FindPlayer()->get_y_pos() - y_rad && y <= FindPlayer()->get_y_pos() + y_rad)) {
				g_Console.writeToBuffer(x, y, ' ', 0x00);
			}
		}
	}
}

void Level::RenderFog()
{
	if (render_fogstate == FogState::STATE_MAX)//Flashlight Fog
	{
		RenderRadius(5, 3);
	}
	if (render_fogstate == FogState::STATE_NONE) //No Fog
	{

	}
	if (render_fogstate == FogState::STATE_MIN)//No Flashlight fog
	{
		RenderRadius(1, 1);
	}
}

void Level::EntityCollision(Entity& entityptr)
{
	Entity& player = *FindPlayer();
	//Checks for collision with each entity. Checks only if the entity is not the player.
	if ((player.get_x_pos() == entityptr.get_x_pos() && player.get_y_pos() == entityptr.get_y_pos() )&& entityptr.get_display() != player.get_display()) {
		switch (entityptr.get_display()) {
		case (char)235:
			entityptr.DoEntityTask(FindGuard());
			break;
		case (char)4:
			entityptr.DoEntityTask(&player);
			break;
		default:
			entityptr.DoEntityTask();
		}
		
	}

	
}

