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
        
        private:
            Arena arena;
            int POS_X = 3;
            int POS_Y = 0;
            int ROTATION = 0;
            int pieceType = 0;
    };
};