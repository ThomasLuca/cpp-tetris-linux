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
            void spawnNewPiece();
            void gameloop();
            void moveDown();
            void snapDown();

        private:
            void lockPiece();
        
        private:
            Arena lockedArena;          // Stores pieces that have already fallen into place
            Arena movingPieceArena;     // Arena with only moving piece
            Collisions movementCheck;
            KeyRegister key;
            int posX = 3;
            int posY = 0;
            int rotation = 0;
            int pieceType = 0;
    };
};