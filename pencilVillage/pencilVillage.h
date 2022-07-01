#pragma once
#include "gameState.h"
#include <ncurses.h>
#include "buildingType.h"

class pencilVillage
{
private:
    gameState game;
    bool TownCentreWasPlaced;
    void printBorders();
    void printOver();
    void printUnder();
    void overLabels();
    void underLabels();
    void placeBuilding(buildingType);
    void moveBuilding(buildingType, std::pair<int, int>, std::vector<std::vector<bool>>);
    bool printBuilding(std::pair<int, int>, std::vector<std::vector<bool>>);

public:
    void printBaseScreen(bool);
    pencilVillage();
    ~pencilVillage();
};
