#include "pencilVillage.h"
#include  <locale.h>
#include <ncursesw/ncurses.h>
#include "buildStruct.h"
#include <iostream>

void pencilVillage::printBaseScreen(bool underOver)
{
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    printBorders();
    if(underOver) {printOver(); overLabels();}
    else {printUnder();}
    /*char ch;
    while ((ch = getch()) != 'q')
    {
        refresh();
    }*/
}

void pencilVillage::printUnder()
{
    
}

void pencilVillage::overLabels()
{
    switch (game.getMapNumber())
    {
    case 1:  //Emerald Copse
        mvprintw(1, 47, "Overworld - Emerald Copse");
        break;
    
    default:
        break;
    }

    mvprintw(45, 2, "Legend: T=WOODS, o=ROCKY, \"=FIELD, ");
    addwstr(L"\u1427");
    printw("=SCRUB, ^=CRAGGY, ");
    addwstr(L"\u1401");
    printw("=Portal \\\\We need to add char for character and building");
}

void pencilVillage::printOver()
{
    std::string temp;
    //wchar_t scrub[] = {1427, L'\0'};
    for (int y = 0; y < 41; y++)
	{
		for (int x = 0; x < 57; x++)
		{
            OverworldTerrain i = game.getOverTerrain(y,x);
			move(3+y, 2+2*x);
            printw(" ");
            if (i.building)
            {
                addwstr(L"\u2395");
                continue;
            } else if(i.rubble)
            {
                addwstr(L"\u2612");
                continue;
            }
            
            switch (i.type)
			{
			case WOODS:
				printw("T");
				break;

			case ROCKY:
				printw("o");
				break;

			case FIELD:
				printw("\"");
				break;

			case SCRUBS:
                //printw(" ");
                addwstr(L"\u2219");
				break;
			case CRAGGY:
				printw("^");
				break;

			case PASSAGE:
				temp = "\u1401";
				addwstr(L"\u1401");
				break;

			default:
				break;
			}
		}
	}
}

void pencilVillage::printBorders()
{
    move(0,0);
    printw("+");
    for (int i = 1; i < 199; i++)
    {
        move(0, i);
        printw("-");
        move(53, i);
        printw("-");
    }
    move(0,199);
    printw("+");
    for (int i = 1; i < 53; i++)
    {
        move(i, 0);
        printw("|");
        move(i, 199);
        printw("|");
        move(i, 118);
        printw("|");
    }
    move(2,0);
    printw("+");
    move(2,118);
    printw("+");    
    move(44,0);
    printw("+");
    move(46, 0);
    printw("+");
    move(44, 118);
    printw("+");
    move(46, 118);
    printw("+");
    move(17,118);
    printw("+");
    move(17, 199);
    printw("+");
    mvprintw(53, 2, "+");
    for (int i = 47; i < 53; i++)
    {
        mvprintw(i, 2, "|");
    }
    
    for (int i = 119; i < 199; i++)
    {
        move(17, i);
        printw("-");
        move(32, i);
        printw("-");
    }
    
    move(32, 118);
    printw("+");
    move(32, 199);
    printw("+");

    for (int i = 1; i < 118; i++)
    {
        move(2,i);
        printw("-");
        move(46, i);
        printw("-");
        move(44,i);
        printw("-");
    }
    move(0, 118);
    printw("+");

    move(53, 0);
    printw("+");
    move(53,199);
    printw("+");
    mvprintw(46, 2, "+");
}

void pencilVillage::placeBuilding(buildingType t)
{
    switch (t)
    {
    case TOWNCENTRE:
    {
        townCentre build(0,0);
        moveBuilding(TOWNCENTRE, build.location, build.building);
        break;
    }

    case BARRACKS:
    {
        barracks build(0,0);
        moveBuilding(BARRACKS, build.location, build.building);
        break;
    }
    case FARM:
    {
        farm build(0,0);
        moveBuilding(FARM,build.location, build.building);
        break;
    }
    case HOUSE:
    {    house build(0,0);
        moveBuilding(HOUSE,build.location, build.building);
        break;
    }
    case MILL:
    {
        mill build(0,0);
        moveBuilding(MILL,build.location, build.building);
        break;
    }
    case OUTPOST:
    {
        outpost build(0,0);
        moveBuilding(OUTPOST,build.location, build.building);
        break;
    }
    case STABLES:
    {
        stables build(0,0);
        moveBuilding(STABLES,build.location, build.building);
        break;
    }
    case DEPOT:
    {
       depot build(0,0);
       moveBuilding(DEPOT,build.location, build.building);
        break;
    }
    case QUARRY:
    {
        quarry build(0,0);
        moveBuilding(QUARRY,build.location, build.building);
        break;
    }
    case ARMOURER:
    {
        armourer build(0,0);
        moveBuilding(ARMOURER,build.location, build.building);
        break;
    }
    case GUILDHALL:
    {
        guildHall build(0,0);
        moveBuilding(GUILDHALL,build.location, build.building);
        break;
    }
    case CHURCH:
    {
        church build(0,0);
        moveBuilding(CHURCH, build.location, build.building);
        break;
    }
    case OVERSEER:
    {
        overseer build(0,0);
        moveBuilding(OVERSEER, build.location, build.building);
        break;
    }
    case TOWER:
    {
        tower build(0,0);
        moveBuilding(TOWER,build.location, build.building);
        break;
    }
    case FORUM:
    {
        forum build(0,0);
        moveBuilding(FORUM,build.location, build.building);
        break;
    }
    case TINKER:
    {
        tinker build(0,0);
        moveBuilding(TINKER,build.location, build.building);
        break;
    }
    case PROSPECTOR:
    {
        prospector build(0,0);
        moveBuilding(PROSPECTOR,build.location, build.building);
        break;
    }
    }

}

bool pencilVillage::printBuilding(std::pair<int, int> location, std::vector<std::vector<bool>> layout)
{
    printBaseScreen(1);
    int rowSize = layout[0].size();
    int colSize = layout.size();
    bool inRange = false;
    bool buildable = true;

    if (rowSize == 2 && colSize == 2)
    {
        inRange = false;
    }
    

    if (TownCentreWasPlaced)
    {
        for (int y = 0; y < colSize; y++)
        {
            for (int x = 0; x < rowSize; x++)
            {
                if (!layout[y][x]) { continue; }
                for (int i = -2; i < 3; i++)
                {
                    for (int j = -2; j < 3; j++)
                    {
                        if (location.first + x + i < 0 || location.first + x + i > 40){ continue; }
                        if (location.second +  y < 0 || location.second + y + j > 56) {continue;}
                        if( game.getOverTerrain(location.first + x + i, location.second + y + j).building) { inRange = true; }
                    }
                    
                }
                
            }
        }
    } else { inRange = true; }
    
    //Add something here so that if building goes over unbuildable terrain, output is different
    for (int y = 0; y < colSize; y++)
    {
        for (int x = 0; x < rowSize; x++)
        {
            mvprintw(location.first + x + 3, 2 * location.second + 2 * y + 2, " ");
            if (layout[y][x])
            {
                if(!inRange || !game.getOverTerrain(location.first + x, location.second + y).buildable) 
                {
                    move(location.first + x + 3, 2* location.second + 2*y + 3);
                    addwstr(L"\u2612");
                    buildable = false;
                    continue;
                }
                addwstr(L"\u2395");
            }
        }
    }
    refresh();
    
    return buildable;
}

void pencilVillage::moveBuilding(buildingType t, std::pair<int, int> location, std::vector<std::vector<bool>> layout)
{
    bool buildable = false;
    
    if(t == DEPOT)
    {
        buildable = false;
    }

    printBuilding(location, layout);
    int ch = 0;
    keypad(stdscr, true);
    while ((ch = getch()) != 'c' && ch != 'C' && (ch != KEY_ENTER || !buildable) && ch != KEY_BACKSPACE && (ch != 10 || !buildable))
    {
        switch (ch)
        {
        case KEY_LEFT:
            if ((location.second - 1) < 0){ break; }
            location.second -= 1;
            buildable = printBuilding(location, layout);
            break;
        case KEY_RIGHT:
            if ((location.second + layout.size()) > 56){ break; }
            location.second += 1;
            buildable = printBuilding(location, layout);
            break;
        case KEY_UP:
            if ((location.first - 1) < 0) {break;}
            location.first -= 1;
            buildable = printBuilding(location, layout);
            break;
        case KEY_DOWN:
            if ((location.first + layout[0].size()) > 40) {break;}
            location.first += 1;
            buildable = printBuilding(location, layout);       
        default:
            break;
        }
    }

    switch (ch)
    {
    case KEY_ENTER:
    case 10:
        if (!TownCentreWasPlaced) { TownCentreWasPlaced = true; }
        game.addBuilding(t, location, layout);
        break;
    
    default:
        break;
    }

    if (t == BARRACKS)
    {
        buildable = false;
    }
}

pencilVillage::pencilVillage() : TownCentreWasPlaced(false)
{
    printBaseScreen(1);
    placeBuilding(TOWNCENTRE);
    placeBuilding(BARRACKS);
    placeBuilding(FARM);
    placeBuilding(HOUSE);
    placeBuilding(MILL);
    placeBuilding(STABLES);
    placeBuilding(DEPOT);
    placeBuilding(QUARRY);
    placeBuilding(ARMOURER);
    placeBuilding(GUILDHALL);
    placeBuilding(CHURCH);
    placeBuilding(OVERSEER);
    placeBuilding(TOWER);
    placeBuilding(FORUM);
    placeBuilding(TINKER);
    placeBuilding(PROSPECTOR);
}
pencilVillage::~pencilVillage(){ curs_set(1); endwin(); }