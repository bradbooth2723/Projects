#include <ncurses.h>
#include <iostream>

int main()
{
    endwin();
    int ch = KEY_LEFT;
    int a = 'c';
    int b = 'C';
    int enter = KEY_ENTER;
    int back = KEY_BACKSPACE;
    char x = 79;
    std::cout << "Left Arrow = " << ch << std::endl;
    std::cout << "c = " << a << std::endl;
    std::cout << "C = " << b << std::endl;
    std::cout << "Back Space = " << back << std::endl;
    std::cout << "Enter = " << enter << std::endl;
    std::cout << x << std::endl;
    int m = 0;
    while (1)
    {
        m = getch();
            std::cout << m << std::endl;
    }
    

}
