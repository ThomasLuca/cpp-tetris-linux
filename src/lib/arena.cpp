#include "arena.h"

namespace Tetris{
    
    void Arena::createArena(){
        for (int i = 0;  i < arenaHeight; i++)
        {
            for (int j = 0; j < arenaWidth; j++)
            {
                arena[i][j] = 0;
            }
        }
    }

    bool Arena::getPoint(int y, int x){
        return arena[y][x];
    }
};