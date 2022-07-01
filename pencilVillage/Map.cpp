#include "Map.h"
#include <iostream>
#include <fstream>

void CampainMap::mapCreator(int mapName)
{
	std::fstream f = openFile(1);
	std::string line;
	
	for (int y = 0; y < 41; y++)
	{
		getline(f, line);
		for(int x = 0; x < 57; x++)
		{
			switch (line[x])
			{
			case '.':
				Overworld[y][x].buildable = true;
				Overworld[y][x].type = SCRUBS;
				break;
			case 'T':
				Overworld[y][x].buildable = true;
				Overworld[y][x].type = WOODS;
				break;
			case '"':
				Overworld[y][x].buildable = true;
				Overworld[y][x].type = FIELD;
				break;
			case 'o':
				Overworld[y][x].buildable = true;
				Overworld[y][x].type = ROCKY;
				break;
			case '^':
				Overworld[y][x].type = CRAGGY;
				Overworld[y][x].buildable = false;
				break;
			case '0':
				Overworld[y][x].type = PASSAGE;
				Overworld[y][x].buildable = false;
			default:
				break;
			}
		}
	}

	for (int y = 0; y < 41; y++)
	{
		getline(f, line);
		for(int x = 0; x < 57; x++)
		{
			switch (line[x])
			{
			case '~':
				Underworld[y][x].type = UNDERWORLD;
				break;
			case '=':
				Underworld[y][x].type = DUNGEONWALL;
				break;
			case '.':
				Underworld[y][x].type = DUNGEONFLOOR;
				break;
			case '!':
				Underworld[y][x].type = DUNGEONFLOOR;
				Underworld[y][x].trap = true;
				break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				Underworld[y][x].type = DUNGEONFLOOR;
				Underworld[y][x].monster = line[x] - 96;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
				Underworld[y][x].type = DUNGEONFLOOR;
				Underworld[y][x].treasure = line[x] - 48;
				break;
			case '^':
				Underworld[y][x].type = PASSAGE;
				break;
			default:
				Underworld[y][x].type = UNDERWORLD;
				//Underworld[y][x].label = 'line[x]';
				break;
			}
		}
	}
	
}

OverworldTerrain CampainMap::getTerrainOverworld(int y, int x) const
{
	return Overworld[y][x];
}

void CampainMap::printOverworld()
{
	std::string temp;
	for (int y = 0; y < 41; y++)
	{
		for (int x = 0; x < 57; x++)
		{
			switch (Overworld[y][x].type)
			{
			case WOODS:
				std::cout << " T";
				break;

			case ROCKY:
				std::cout << " o";
				break;

			case FIELD:
				std::cout << " \"";
				break;

			case SCRUBS:
				temp = "\u1427";
				std::cout << " " << temp;
				break;
			case CRAGGY:
				std::cout << " ^";
				break;

			case PASSAGE:
				temp = "\u1401";
				std::cout << " " << temp;
				break;

			default:
				std::cout << "XX";
				break;
			}
		}
	}
}

void CampainMap::setBuildable(int y, int x, bool t)
{
	Overworld[y][x].buildable = t;	
}

void CampainMap::setBuilding(int y, int x, bool t)
{
	Overworld[y][x].building = t;
}

//TODO: Add way of telling if monster is defeated.
void CampainMap::printUnderworld()
{
	std::string temp;
	for (int y = 0; y < 41; y++)
	{
		for (int x = 0; x < 57; x++)
		{
			switch (Underworld[y][x].type)
			{
			case UNDERWORLD:
				std::cout << "  ";
				break;

			case DUNGEONFLOOR:
				if (Underworld[y][x].trap)
				{
					std::cout << " !";
				} else if (Underworld[y][x].monster > 0)
				{
					char l = Underworld[y][x].monster + 96;
					std::cout << " " << l;
				} else if (Underworld[y][x].treasure > -1)
				{
					std::cout << " " << Underworld[y][x].treasure;
				}else
				{
				temp = "\u1427";
				std::cout << " " << temp;
				}
				break;

			case DUNGEONWALL:
				//temp = "\u220E";
				temp = "\u2395";
				std::cout << " " << temp;
				break;

			case PASSAGE:
				temp = "\u1403";
				std::cout << " " << temp;
				break;
			default:
				std::cout << "XX";
				break;
			}
		}
		std::cout << std:: endl;
	}
}

std::fstream CampainMap::openFile(int mapName)
{
	std::fstream f;

	//Eventually will add more maps
	switch (mapName)
	{
		case 1:
			f.open("./maps/EmeraldCopse.txt", std::fstream::in);
			break;
		default:
			perror("Map does not exist lol");
			exit(2);
	}

	if (!f.is_open())
	{
		perror("File failed to open or not found");
		exit(2);
	}

	return f;
}

CampainMap::CampainMap()
{
	mapCreator(1);
	map = 1;
}

CampainMap::~CampainMap()
{
}