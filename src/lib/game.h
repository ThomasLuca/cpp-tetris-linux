#pragma once

#include "piece.h"
#include "arena.h"

namespace Tetris{

    class Game{
        public:
            Game();
            std::string drawArena();
            void movement();
            void generatePiece();
            void moveDown();

        private:
            bool isValidMovement();
        
        private:
            Arena lockedArena;          // Stores pieces that have already fallen into place
            Arena movingPieceArena;     // Arena with only moving piece
            int POS_X = 3;
            int POS_Y = 0;
            int ROTATION = 0;
            int pieceType = 0;
    };
};