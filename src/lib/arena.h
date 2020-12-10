#pragma once

#include "piece.h"

namespace Tetris{
    class Arena
    {
        public:
            int getPoint(int y, int x);
            void setPoint(int y, int x, int color);
            void placePiece(int y, int x, int pieceType, int pieceRotation);
            void createArena();
            int getWidth();
            int getHeight();
            int checkClearLine(int y);
            bool isGameOver();

        private:
            void clearLine(int line);
            void relocateLines(int line);

        private:
            int ARENAWIDTH = 10;
            int ARENAHEIGHT = 21;
            int arena[21][10];
            Piece pieces;
    };
};