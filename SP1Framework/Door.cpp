#include "Door.h"
#include "HUD.h"

ifstream myfile_in(".Txt/D00.txt");
ofstream myfile_out("output.txt");
string line;

Door::Door(COORD c_pos, MapMaker* map)
{
    set_pos(c_pos);
    set_display((char)93);
    entity_map = map;
    colour = 0x2;
    timer = 0;
    isActive = true;
}


Door::Door(int y_pos, int x_pos, MapMaker* map)
{
    set_xpos(x_pos);
    set_ypos(y_pos);
    set_display((char)93);
    entity_map = map;
    colour = 0x2;
    timer = 0;
    isActive = true;
}

Door::~Door()
{
}


void Door::move(int button_pressed)
{
}

void find_and_replace(string& source, string find, string replace)
{
    size_t j;

    for (; (j = source.find(find)) != string::npos; ) {
        source.replace(j, find.length(), replace);
    }

    myfile_out << source << endl;
}

void Door::DoEntityTask(Entity* player)
{
    if (myfile_in.is_open())
    {
        int i = 0, j;
        //string strcomma ; 
          // string strspace ; 

        while (!myfile_in.eof())
        {

            getline(myfile_in, line);

            string strfind = "`";
            string strreplacewith = " ";

            find_and_replace(line, strfind, strreplacewith);


            i++;

        }

        myfile_in.close();
    }
    toggle();
}

bool Door::collide(COORD entity_pos)
{
    return collide(entity_pos.X, entity_pos.Y);;
}

bool Door::collide(int entity_xpos, int entity_ypos)
{
    COORD pos;
    pos.X = entity_xpos;
    pos.Y = entity_ypos;
    if (entity_map->getMapArray()[entity_ypos][entity_xpos] == ' ') {
        return false;
    }
    else {
        return true;
    }
}