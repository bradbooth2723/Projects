#pragma once
enum TerrainType
{
	WOODS, ROCKY, FIELD, SCRUBS, CRAGGY, BUILDING, PASSAGE, UNDERWORLD, DUNGEONWALL, DUNGEONFLOOR
	/* 
	TERRAIN TYPE:
		WOODS = T
		ROCKY = o
		FIELD = "
		SCRUB = .
		CRAG  = ^
	*/
};

struct OverworldTerrain
{
	TerrainType type;
	bool buildable;
	bool building;
	bool rubble;
	bool hero;

	OverworldTerrain() : buildable(1), building(0), rubble(0), hero(0)
	{

	}
};


struct UnderworldTerrain
{
	TerrainType type;
	bool hero;
	bool trap;
	int monster;
	int treasure;
	char label;

	UnderworldTerrain() : hero(0), trap(0), monster(-1), treasure(-1){}
};