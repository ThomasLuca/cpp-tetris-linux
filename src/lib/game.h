#pragma once

#include "piece.h"
#include "arena.h"
#include "collisions.h"
#include "keyRegister.h"

namespace Tetris{

    class Game{
        public:
            Game();
            std::string drawArena();
            void movement();
            void generatePiece();
            void moveDown();
            void spawnNewPiece();
            void gameloop();

        private:
            void lockPiece();
        
        private:
            Arena lockedArena;          // Stores pieces that have already fallen into place
            Arena movingPieceArena;     // Arena with only moving piece
            Collisions movementCheck;
            KeyRegister key;
            int POS_X = 3;
            int POS_Y = 0;
            int ROTATION = 0;
            int pieceType = 0;
    };
};