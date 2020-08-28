#pragma once
#include "Framework/console.h"
#include <iostream>
#include <fstream>
#include <string>



using namespace std;
extern Console g_Console;

class MapMaker
{
private:
	char** MapArray;
	int no_of_rows, no_of_col;



public:
	MapMaker();
	~MapMaker();
	//Takes the Txt file and puts it into the array
	void Load(string filepath);

	//Renders the Contents of the text file from origin point coord
	void Render(COORD origin, COORD end);
	void Render(SHORT origin_x, SHORT origin_y, SHORT end_x, SHORT end_y);

	//Gets character from Coordinate
	char getFromCoord(COORD c);
	char getFromCoord(SHORT x, SHORT y);
	//Set at coord (Do not use unless for very specific purposes)
	void setToCoord(COORD c, char display);
	void setToCoord(SHORT x, SHORT y, char display);

	
	char** getMapArray();
	int getEntityCount();
	int get_row();
	int get_col();

};

