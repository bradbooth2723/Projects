#include <iostream>
#include <ncurses.h>
#include <vector>
int main()
{
    std::vector<std::vector<bool>> building(4, std::vector<bool>(4, false));
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
    for (int y = 0; y < building.size(); y++)
    {
        for (int x = 0; x < building[0].size(); x++)
        {
            if (building[x][y])
            {
                std::cout << 1;
            } else
            {
                std::cout << 0;
            }
        }
        std::cout << std::endl;
        
    }
    std::cout << std::endl;
 
}