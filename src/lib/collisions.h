#pragma once
#include "arena.h"
#include "keyRegister.h"

namespace Tetris{
    class Collisions
    {
        public:
            void initArena(Arena *mp, Arena *la);
            bool isValidMovement(KeyRegister::Key key);
        private:
            Arena *movingPieceArena;
            Arena *lockedArena;
    };
};
