#include "scoreboard.h"
#include <iostream>

namespace Tetris{
    void Scoreboard::innitScoreboard(){
        for (int i = 0;  i < 3; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                head[i][j] = "  ";
            }
        }
    }

    void Scoreboard::drawHorizonalBorder(){
        std::cout << "\033[;97m██████████████████████\033[0m" <<std::endl;
    }

    void Scoreboard::placePiece(){
        for (int i = 0; i < 3; i++)
        {
            for (int j = 6; j < 10; j++)
            {
                if (piece.getBlockOfPiece(this->pieceType, 0, i, j-6))
                {
                    head[i][j] = colors.setChar(piece.getBlockOfPiece(this->pieceType, 0, i, j-6), 0);
                }
            }
        }
    }

    void Scoreboard::printHead(){
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                std::cout << head[i][j];
            }
            std::cout << std::endl;
        }
    }

    void Scoreboard::printScoreboard(){
        drawHorizonalBorder();
        printHead();
        drawHorizonalBorder();
    }

    void Scoreboard::setNextPiece(int pieceType){
        this->pieceType = pieceType;
        innitScoreboard();
        placePiece();
    }

    int Scoreboard::getNextPiece(){
        return this->pieceType; 
    }
};