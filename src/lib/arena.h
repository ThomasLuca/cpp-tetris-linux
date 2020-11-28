#pragma once

#include "piece.h"

namespace Tetris{
    class Arena
    {
        public:
            bool getPoint(int y, int x);
            void lockPiece(int y, int x, int pieceType, int pieceRotation);
            void createArena();
            int getWidth();
            int getHeight();

        private:
            int arenaWidth = 10;
            int arenaHeight = 21;
            bool arena[21][10];
            Piece pieces;
    };
};