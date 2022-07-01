#pragma once
#include <string>
#include <fstream>
#include "TerrainType.h"

class CampainMap
{
public:
	void Create_Emerald();
	void mapCreator(int);
	void printOverworld();
	void printUnderworld();
	void setBuildable(int, int, bool);
	void setBuilding(int, int, bool);
	OverworldTerrain getTerrainOverworld(int, int) const;
	CampainMap();
	~CampainMap();
	int map;
private:
	OverworldTerrain Overworld[41][57];
	UnderworldTerrain Underworld[41][57];
	std::fstream openFile(int);
};

