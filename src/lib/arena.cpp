#include "arena.h"

namespace Tetris{
    
    /*  Initializes an empty arena (every place = False)    */
    void Arena::createArena(){
        for (int i = 0;  i < arenaHeight; i++)
        {
            for (int j = 0; j < arenaWidth; j++)
            {
                arena[i][j] = 0;
            }
        }
    }

    /*  Returns boolean value of any given place in the arena   */
    bool Arena::getPoint(int y, int x){
        return arena[y][x];
    }

    /*  Places pieces anywhere in the arena by enabling certain positions   */
    void Arena::lockPiece(int y, int x, int piece, int rotation){
        for (int i = y; i < y + 4; i++)
        {
            for (int j = x; j < x + 4; j++)
            {
                if (pieces.getBlockOfPiece(piece, rotation, i - y, j - x))
                {
                    arena[i][j] = 1;
                }
            }
        }
    }

    int Arena::getWidth(){
        return arenaWidth;
    }

    int Arena::getHeight(){
        return arenaHeight;
    }

};