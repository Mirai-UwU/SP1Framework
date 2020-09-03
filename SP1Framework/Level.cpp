#include "Level.h"
#include "HUD.h"

void Level::Build()
{
	this_map.Load(filepath);
	entitycount = this_map.getEntityCount();
	entity_list = new Entity* [entitycount];
	initial_pos = new COORD[entitycount];
	FindEntities();
	//Removes the entity from the Map
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

			//Creates entities according to symbol on the txt file.
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
			case ']':
				entity_list[count++] = new Door(coord, &this_map);
				break;
			case '?':
				entity_list[count++] = new Power(coord, &this_map);
				break;
			default:
				break;
			}

		
		}
	}
	
}


Level::Level()
{
	//Default Parameters
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
			if (entity_list[i]->active()) {
				return entity_list[i];
			}
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
			if (entity_list[i]->active()) {
				return entity_list[i];
			}
		}
	}
}

Entity* Level::FindBombed(int which)
{
	if (which < 0 || which >= entitycount) {
		which = entitycount;
	}

	for (int i = which; i < entitycount; i++) {
		if (entity_list[i]->get_display() == (char)3) {
			if (entity_list[i]->active()) {
				return entity_list[i];
			}
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

		//Only Updates entity If entity is Active
		if (ent.active()) {
			char theEntity = entity_list[i]->get_display();
			switch (theEntity) {
			case (char)2:
				if (!(hud.bombhandler())) {

					if ((int)g_dElapsedTime % 2) {
						if (ent.get_timer() > 0.02) {
							ent.move(rand() % K_COUNT);
							ent.reset_timer();
						}

					}
				}
				/// Stuns the guard
				else {
					for (int i = 0; i < entitycount; i++) {
						FindGuard(i)->set_display((char)3);
						FindGuard(i)->reset_timer();
					}
				}
				break;
			case (char)3:
				//Turns guard back after bombed.
				if (ent.get_timer() > 5) {
					for (int i = 0; i < entitycount; i++) {
						FindBombed(i)->set_display((char)2);
						FindBombed(i)->reset_timer();
					}
				}
				break;
			case (char)233:
				if (ent.get_timer() > 1) {
					hud.set_flashlight_time(hud.get_flashlight_time() - 1);
					hud.set_powertime(hud.get_powertime() - 1);
					ent.reset_timer();
				}
				break;
//			case (char)168:
//					if (ent.get_timer() > 1) {
//						hud.set_powertime(hud.get_powertime() - 1);
//						ent.reset_timer();
//					}
//				break;
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

					

				break;
			default:
				break;
			}
			EntityCollision(ent);

			if (hud.teleporthandler()) { //If Teleporter is held and K_TELEPORTER is pressed
				if (getPlayerInput() == K_TELEPORTER)
				{
					FindPlayer()->set_xpos(rand() % 100);
					FindPlayer()->set_ypos(rand() % 20);
					while (FindPlayer()->collide(FindPlayer()->get_pos()) )
					{
						FindPlayer()->set_xpos(rand() % 100);
						FindPlayer()->set_ypos(rand() % 20);
					}
				}
			}

			if (hud.get_powertime() > 0) {
				setFog(3);
			}
			else if (hud.get_flashlight_time() < 0) {
				setFog(1);
			}
			else {
				setFog(2);
			}

		}
	}

	//Resets hud values when lives < 0
	if (hud.getLives() < 0) {
		hud.setLives(900);
		hud.set_flashlight_time(120);
		hud.set_powertime(0);
		Reset();
		g_eGameState = S_DEATH;

	}
	
	

}


void Level::Render()
{
	this_map.Render(0, 0, 102, 20);
	for (int i = 0; i < entitycount; ++i) {
		Entity& ent = *entity_list[i];
		//Only renders if entity is active
		if (ent.active2()) {
			g_Console.writeToBuffer(ent.get_pos(), ent.get_display(), ent.get_colour());
		}
	}
	RenderFog();
	hud.render_HUD();
}

void Level::Reset()
{
	for (int i = 0; i < entitycount; i++) {
		Entity& ent = *entity_list[i];
		if (!ent.active()) {
			ent.toggle();
		}
		ent.set_pos(initial_pos[i]);
		ResetTimers();
	}
	hud.set_flashlight_time(120);
	hud.set_powertime(0);
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
	if (render_fogstate == FogState::STATE_POW)//Power up Fog
	{
		RenderRadius(15, 6);
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
	if ((player.get_x_pos() == entityptr.get_x_pos() && player.get_y_pos() == entityptr.get_y_pos()) && entityptr.get_display() != player.get_display())
	{
		switch (entityptr.get_display())
		{

		case (char)93:
		{
			entityptr.DoEntityTask();
			COORD coord;
			int count = 0;
			for (int row = 0; row < this_map.get_row(); row++)
			{
				coord.Y = row;
				for (int col = 0; col < this_map.get_col(); col++)
				{
					coord.X = col;
					char entity = this_map.getFromCoord(coord);
					if (this_map.getFromCoord(82, 13) == '`')
					{
						this_map.setToCoord(82, 13, ' ');
					}
					if (this_map.getFromCoord(82, 14) == '`')
					{
						this_map.setToCoord(82, 14, ' ');
					}
				}
			}
		}
		break;
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

void Level::powerUp()
{
	hud.set_powertime(6);
}