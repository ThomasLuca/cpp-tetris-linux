#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "game.h"


namespace Tetris{

    Game::Game(){
        drawArena();
    }

    std::string Game::drawArena(){
        arena.createArena();
        int pieceType = generatePiece();
        arena.lockPiece(START_POS_Y, START_POS_X, pieceType, START_ROTATION);
        
        std::stringstream output;
        for (int i = 0; i < arena.getHeight(); i++)
        {
            for (int j = 0; j < arena.getWidth(); j++)
            {
                if (arena.getPoint(i, j))
                {
                    output << "\033[;32m██\033[0m";
                } else {
                    output << ". ";
                }
            }
            output << std::endl;
        }
        return output.str();
    }

    int Game::generatePiece(){
        srand (time(NULL));
        int piece = rand() % 7;
        return piece;
    }
};