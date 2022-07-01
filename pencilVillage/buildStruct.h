#pragma once
#include <utility>
#include "TerrainType.h"
#include <vector>

//Only applies to townhall level 1.  After town hall level 1, will prob just manually go in and edit map.
struct townCentre
{
    std::vector<std::vector<bool>> building; 
    std::pair<int, int> location;

    townCentre(): building(4, std::vector<bool>(4, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;

        building[0][1] = true;
        building[3][1] = true;

        building[0][2] = true;
        building[3][2] = true;

        building[0][3] = true;
        building[3][3] = true;
    }

    townCentre(int y, int x): building(4, std::vector<bool>(4, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;

        building[0][1] = true;
        building[3][1] = true;

        building[0][2] = true;
        building[3][2] = true;

        building[0][3] = true;
        building[3][3] = true;
    }
};

struct barracks
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    barracks(): building(3, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[2][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;

        building[0][2] = true;
        building[2][2] = true;
    }
    barracks(int y, int x): building(3, std::vector<bool>(3, false)), location(y, x)
    {
        building[0][0] = true;
        building[2][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;

        building[0][2] = true;
        building[2][2] = true;
    }
};

struct farm
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    farm(): building(2, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
        building[1][2] = true;
    }
    farm(int y, int x): building(2, std::vector<bool>(3, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
        building[1][2] = true;
    }
};

struct house
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    house(): building(2, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
    }
    house(int y, int x): building(2, std::vector<bool>(3, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
    }
};

struct mill
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    mill(): building(3, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
    }
    mill(int y, int x): building(3, std::vector<bool>(3, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
    }
};

struct outpost
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;
    TerrainType terrain;

    outpost(): building(2, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
    }
    outpost(int y, int x): building(2, std::vector<bool>(3, false)), location(y, x)
    {
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
    }
};

struct stables
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    stables(): building(3, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;

        building[0][2] = true;
        building[2][2] = true;
    }
    stables(int y, int x): building(3, std::vector<bool>(3, false)), location(y, x)
    {
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;

        building[0][2] = true;
        building[2][2] = true;
    }
};

struct depot
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    depot(): building(2, std::vector<bool>(2, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;
    }
    depot(int y, int x): building(2, std::vector<bool>(2, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;
    }
};

struct quarry
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    quarry(): building(4, std::vector<bool>(2, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;

        building[0][1] = true;
        building[1][1] = true;
    }
    quarry(int y, int x): building(4, std::vector<bool>(2, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;

        building[0][1] = true;
        building[1][1] = true;
    }
};

struct armourer
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    armourer(): building(3, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;

        building[2][1] = true;

        building[1][2] = true;
        building[2][2] = true;
    }
    armourer(int y, int x): building(3, std::vector<bool>(3, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;

        building[2][1] = true;

        building[1][2] = true;
        building[2][2] = true;
    }
};

struct guildHall
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    guildHall(): building(4, std::vector<bool>(1, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;
    }
    guildHall(int y, int x): building(4, std::vector<bool>(1, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;
    }
};

struct church
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    church(): building(4, std::vector<bool>(2, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;
        building[3][1] = true;
    }
    church(int y, int x): building(4, std::vector<bool>(2, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;
        building[3][1] = true;
    }
};

struct overseer
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    overseer(): building(3, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[1][0] = true;
        building[2][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;

        building[0][2] = true;
        building[1][2] = true;
    }
    overseer(int y, int x): building(3, std::vector<bool>(3, false)), location(y, x)
    {
        building[1][0] = true;
        building[2][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;

        building[0][2] = true;
        building[1][2] = true;
    }
};

struct tower
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    tower(): building(3, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;

        building[1][2] = true;

    }
    tower(int y, int x): building(3, std::vector<bool>(3, false)), location(y, x)
    {
        building[1][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;

        building[1][2] = true;
    }
};

struct forum
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    forum(): building(3, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;

        building[0][1] = true;
        building[2][1] = true;

        building[0][2] = true;
        building[1][2] = true;
        building[2][2] = true;
    }
    forum(int y, int x): building(3, std::vector<bool>(3, false)), location(y, x)
    {
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;

        building[0][1] = true;
        building[2][1] = true;

        building[0][2] = true;
        building[1][2] = true;
        building[2][2] = true;
    }
};
struct tinker
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    tinker(): building(2, std::vector<bool>(3, false)), location(-1, -1)
    {
        building[0][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
    }
    tinker(int y, int x): building(2, std::vector<bool>(3, false)), location(y, x)
    {
        building[0][0] = true;

        building[0][1] = true;
        building[1][1] = true;

        building[0][2] = true;
    }
};

struct prospector
{
    std::vector<std::vector<bool>> building;
    std::pair<int, int> location;

    prospector(): building(4, std::vector<bool>(2, false)), location(-1, -1)
    {
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[3][1] = true;
    }
    prospector(int y, int x): building(4, std::vector<bool>(2, false)), location(y, x)
    {
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[3][1] = true;
    }
};


/*
        building[0][0] = true;
        building[1][0] = true;
        building[2][0] = true;
        building[3][0] = true;

        building[0][1] = true;
        building[1][1] = true;
        building[2][1] = true;
        building[3][1] = true;

        building[0][2] = true;
        building[1][2] = true;
        building[2][2] = true;
        building[3][2] = true;

        building[0][3] = true;
        building[1][3] = true;
        building[2][3] = true;
        building[3][3] = true;
*/