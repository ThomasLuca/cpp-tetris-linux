#pragma once
#include <string>
#include "piece.h"
#include "colors.h"

namespace Tetris{
    class Scoreboard
    {
    public:
        void innitScoreboard();
        void setNextPiece(int pieceType);
        int getNextPiece();
        void printScoreboard();
    private:
        void drawHorizonalBorder();
        void placePiece();
        void printHead();
    private:
        int pieceType = 0;
        std::string head[3][10];
        Piece piece;
        Colors colors;
    };
};