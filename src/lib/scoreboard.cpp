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
    
    void Scoreboard::placeBorder(){
        for (int i = 0; i < 3; i++)
        {
            head[i][5] = " \033[;97m█\033[0m";
        }
    }

    void Scoreboard::placeScore(int points){
        std::string score = "Score:";
        std::string point = std::to_string(points);
        if(point.length() % 2){
            point += ' ';
        }
        for (unsigned int i = 0; i < score.length() / 2; i++)
        {
            head[0][i] = score.substr(2*i, 2);
        }
        for (unsigned int i = 0; i < point.length() / 2; i++)
        {
            head[1][i] = point.substr(2*i, 2);
        }
    }

    void Scoreboard::printHead(){
        for (int i = 0; i < 3; i++)
        {
            std::cout << "\033[;97m█\033[0m";
            for (int j = 0; j < 10; j++)
            {
                std::cout << head[i][j];
            }
            std::cout << "\033[;97m█\033[0m" << std::endl;
        }
    }

    void Scoreboard::printScoreboard(){
        drawHorizonalBorder();
        placeBorder();
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