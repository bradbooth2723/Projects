#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <ncurses.h>
void printBorders();

int main()
{
    /*printf("\033[2J");
    std::cout << "Hello World";

    printf("\033[%d;%dH", 1, 1);
    std::cout << "Hello World2";*/

    
    initscr();
    printBorders();

}

void printBorders()
{

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
        move(i, 119);
        printw("|");
    }
    move(2,0);
    printw("+");
    move(2,119);
    printw("+");    
    move(43,0);
    printw("+");
    move(45, 0);
    printw("+");
    move(43, 119);
    printw("+");
    move(45, 119);
    printw("+");
    move(17,119);
    printw("+");
    move(17, 199);
    printw("+");
    for (int i = 120; i < 199; i++)
    {
        move(17, i);
        printw("-");
        move(32, i);
        printw("-");
    }
    
    move(32, 119);
    printw("+");
    move(32, 199);
    printw("+");

    for (int i = 1; i < 119; i++)
    {
        move(2,i);
        printw("-");
        move(43, i);
        printw("-");
        move(45,i);
        printw("-");
    }
    move(0, 119);
    printw("+");

    move(53, 0);
    printw("+");
    move(53,199);
    printw("+");
        char ch;
    while (ch = getch() != 'q')
    {
        refresh();
    }
	//getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
}