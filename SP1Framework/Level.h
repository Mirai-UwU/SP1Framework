#pragma once
#include "Entity.h"
#include "Player.h"
#include "Exit.h"
#include "guard.h"
#include "Bomb.h"
#include "Teleporter.h"
#include "MapMaker.h"
#include "Sound.h"
#include "Bomb.h"

extern Console g_Console;
extern double g_dElapsedTime;

class Level
{
private:
	//file for level
	string filepath;
	enum class FogState {
		STATE_NONE,
		STATE_MIN,
		STATE_MAX,
		STATE_COUNT
	};

	FogState render_fogstate;

	//Loads everything up
	void Build();
	//Finds and Puts Entities into entity_list
	void FindEntities();
	COORD* initial_pos;
	Sound se;

protected:
	
	MapMaker this_map;
	//Dynamic Array of Entities
	Entity** entity_list;
	int entitycount;
public:
	Level();
	Level(string filename);
	~Level();

	//use if cannot initialise at start
	void Load(string filename); 

	//Sets All Individual Entity's timers
	void SetTimers(double t);
	void ResetTimers();
	
	//Sets FogState based on number
	void setFog(int i);

	///Returns the Entity you are looking for
	Entity* FindPlayer();
	//Finds the first guard in the list
	Entity* FindGuard();
	//Finds the guard depending on number which
	Entity* FindGuard(int which); 
	Entity* FindExit();
	


	void Update();
	void Render();
	void Reset();

	//Level functions
	void RenderRadius(int x_rad, int y_rad);
	void RenderFog();
	void EntityCollision(Entity& entityptr);


	
};

