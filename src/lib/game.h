#pragma once

#include "piece.h"
#include "arena.h"

namespace Tetris{

    class Game{
        public:
            Game();
            std::string drawArena();

        private:
            int generatePiece();
        
        private:
            Arena arena;
            int const START_POS_X = 3;
            int const START_POS_Y = 0;
            int const START_ROTATION = 0;
    };
};