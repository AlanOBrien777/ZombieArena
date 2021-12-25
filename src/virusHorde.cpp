//
//  zombieHorde.cpp
//  Zombie Arena
//

#include "../includes/virusArena.h"
#include "../includes/Virus.h"

Virus* createHorde(int numViruses, IntRect arena)
{
    Virus* viruses = new Virus[numViruses];

    int maxY = arena.height - 20;
    int minY = arena.top + 20;
    int maxX = arena.width - 20;
    int minX = arena.left + 20;

    for (int i = 0; i < numViruses; i++)
    {

        // Which side should the virus spawn
        int side = (rand() % 4);
        float x = 0, y = 0;

        switch (side)
        {
        case 0:
            // left
            x = minX;
            y = (rand() % maxY) + minY;
            break;

        case 1:
            // right
            x = maxX;
            y = (rand() % maxY) + minY;
            break;

        case 2:
            // top
            x = (rand() % maxX) + minX;
            y = minY;
            break;

        case 3:
            // bottom
            x = (rand() % maxX) + minX;
            y = maxY;
            break;
        }

        int type = (rand() % 1);

        // Spawn the new zombie into the array
        viruses[i].spawn(x, y, type, i);

    }
    return viruses;
}




