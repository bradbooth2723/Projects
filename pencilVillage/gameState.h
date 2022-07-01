#pragma once
#include "numBuilding.h"
#include "resources.h"
#include "buildLocations.h"
#include "affinityaversion.h"
#include <vector>
#include "Map.h"
#include "buildingType.h"

class gameState
{
private:
    int round;
    int objective;
    int character;
    bool mods[26];
    int gems;
    int lost;
    int threat;
    numBuildings build;  //tracks number of buildings built and max number
    resources resource;
    buildLocations Loc;
    Affinity affinity;
    Aversion aversion;
    std::vector<int> heroes;  //I think when destroying guild hall, last two added are deleted
    CampainMap map;
    //Maybe add a list of available actions.  Maybe make them a tuple for ones that are once per turn.

    

public:
    gameState(/* args */);
    ~gameState();
    void printGame();
    OverworldTerrain getOverTerrain(int, int) const;
    int getMapNumber();
    void addBuilding(buildingType, std::pair<int, int>, std::vector<std::vector<bool>>);
};


