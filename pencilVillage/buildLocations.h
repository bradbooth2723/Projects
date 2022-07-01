#pragma once
#include <utility>
#include "TerrainType.h"
#include <vector>

struct buildLocations
{
    std::pair<int, int> TownCentreLocation;
    std::vector<std::pair<int, int>> BarracksLocation;
    std::vector<std::pair<int, int>> FarmLocation;
    std::vector<std::pair<int, int>> HouseLocation;
    std::vector<std::pair<int, int>> MillLocation;
    //TODO: Track what terrain an outpost is placed on.
    std::vector<std::pair<int, int>> OutpostLocation;
    //std::vector<std::pair<std::pair<int, int>, TerrainType>> OutpostLocation;  //Have to track what terrain outpost is on
    std::vector<std::pair<int, int>> StableLocation;
    std::vector<std::pair<int, int>> DepotLocation;
    std::vector<std::pair<int, int>> QuarryLocation;
    std::vector<std::pair<int, int>> ArmourerLocation;
    std::vector<std::pair<int, int>> GuildhallLocation;
    std::vector<std::pair<int, int>> ChurchLocation;
    std::vector<std::pair<int, int>> OverseerLocation;
    std::vector<std::pair<int, int>> TowerLocation;
    std::vector<std::pair<int, int>> ForumLocation;
    std::vector<std::pair<int, int>> TinkerLocation;
    std::vector<std::pair<int, int>> ProspectorLocation;
};
