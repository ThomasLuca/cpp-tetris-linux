#include "arena.h"

namespace Tetris{
    
    /*  Initializes an empty arena (every place = False)    */
    void Arena::createArena(){
        for (int i = 0;  i < ARENAHEIGHT; i++)
        {
            for (int j = 0; j < ARENAWIDTH; j++)
            {
                arena[i][j] = 0;
            }
        }
    }

    /*  Returns boolean value of any given place in the arena   */
    bool Arena::getPoint(int y, int x){
        return arena[y][x];
    }

    void Arena::setPoint(int y, int x){
        arena[y][x] = 1;
    }

    /*  Places pieces anywhere in the arena by enabling certain positions   */
    void Arena::placePiece(int y, int x, int piece, int rotation){
        for (int i = y; i < y + 4; i++)
        {
            for (int j = x; j < x + 4; j++)
            {
                if (pieces.getBlockOfPiece(piece, rotation, i - y, j - x))
                {
                    setPoint(i, j);
                }
            }
        }
    }

    int Arena::checkClearLine(int y){
        int lineCompletion = 0;
        int completedLines = 0;
        for (int i = y; i < y + 4; i++)
        {
            for (int j = 0; j < ARENAWIDTH; j++)
            {
                if (arena[i][j])
                {
                    lineCompletion++;
                }
                if (lineCompletion == ARENAWIDTH)
                {
                    clearLine(i);
                    completedLines++;
                }
            }
            lineCompletion = 0;
        }
        return completedLines;
    }

    void Arena::clearLine(int line){
        for(int j = 0; j < ARENAWIDTH; j++)
        {
            arena[line][j] = 0;
        }
        relocateLines(line);
    }

    void Arena::relocateLines(int line){
        for (int i = line; i > 0; i--)
        {
            for (int j = 0; j < ARENAWIDTH; j++)
            {
                arena[i][j] = arena[i-1][j];
            }
        }
    }

    bool Arena::isGameOver(){
        int count = 0;
        for (int i = 0; i < ARENAWIDTH - 1; i++)
        {
            if (arena[1][i])
            {
                count++;
            } 
        }
        return (count >= 1) ? true : false;
    }

    int Arena::getWidth(){
        return ARENAWIDTH;
    }

    int Arena::getHeight(){
        return ARENAHEIGHT;
    }

};