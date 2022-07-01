#include "gameState.h"

OverworldTerrain gameState::getOverTerrain(int y, int x) const
{
    
    return map.getTerrainOverworld(y, x);
}

int gameState::getMapNumber() { return map.map; }

void gameState::addBuilding(buildingType t, std::pair<int, int> location, std::vector<std::vector<bool>> layout)
{
    //TODO: Edit Map
    //      Add to list of buildings
    bool a = true;
    if (t == FARM)
    {
        if(!a) {a = true;}
    }
    

    int rowSize = layout[0].size();
    int colSize = layout.size();
    for (int y = 0; y < colSize; y++)
    {
        for (int x = 0; x < rowSize; x++)
        {
            map.setBuildable(location.first + x, location.second + y, false);
            if (layout[y][x])
            {
                map.setBuilding(location.first + x, location.second + y, true);
            } else { continue; }
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (location.first + i < 0 || location.first + i > 40){ continue; }
                    if (location.second + j < 0 || location.second + j > 56) {continue;}
                    map.setBuildable(location.first + x + i, location.second + y + j, false);
                }
            }
        }
    }

    resource.population += 1;
    build.total += 1;
    switch (t)
    {
    case TOWNCENTRE:
    {
        build.townCentreLevel = 1;
        Loc.TownCentreLocation = location;
        break;
    }

    case BARRACKS:
    {
        build.barracks += 1;
        Loc.BarracksLocation.push_back(location);
        break;
    }
    case FARM:
    {
        build.farm += 1;
        Loc.FarmLocation.push_back(location);
        break;
    }
    case HOUSE:
    {    
        build.house += 1;
        Loc.HouseLocation.push_back(location);
        break;
    }
    case MILL:
    {
        build.mill += 1;
        Loc.MillLocation.push_back(location);
        break;
    }
    case OUTPOST:
    {
        build.outpost += 1;
        Loc.OutpostLocation.push_back(location);
        break;
    }
    case STABLES:
    {
        build.stables += 1;
        Loc.StableLocation.push_back(location);
        break;
    }
    case DEPOT:
    {
        build.depot += 1;
        Loc.DepotLocation.push_back(location);
        break;
    }
    case QUARRY:
    {
        build.quarry += 1;
        Loc.QuarryLocation.push_back(location);
        break;
    }
    case ARMOURER:
    {
        build.armourer += 1;
        Loc.ArmourerLocation.push_back(location);
        break;
    }
    case GUILDHALL:
    {
        build.guildhall += 1;
        Loc.GuildhallLocation.push_back(location);
        break;
    }
    case CHURCH:
    {
        build.church += 1;
        Loc.ChurchLocation.push_back(location);
        break;
    }
    case OVERSEER:
    {
        build.overseer += 1;
        Loc.OverseerLocation.push_back(location);
        break;
    }
    case TOWER:
    {
        build.tower += 1;
        Loc.TowerLocation.push_back(location);
        break;
    }
    case FORUM:
    {
        build.forum += 1;
        Loc.ForumLocation.push_back(location);
        break;
    }
    case TINKER:
    {
        build.tinker += 1;
        Loc.TinkerLocation.push_back(location);
        break;
    }
    case PROSPECTOR:
    {
        build.prospector += 1;
        Loc.ProspectorLocation.push_back(location);
        break;
    }
    }

}

gameState::gameState()
{
}

gameState::~gameState()
{
}