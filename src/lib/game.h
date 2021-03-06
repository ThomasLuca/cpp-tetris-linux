#pragma once

#include "piece.h"
#include "arena.h"
#include "collisions.h"
#include "keyRegister.h"
#include "score.h"
#include "colors.h"
#include "scoreboard.h"
#include "gameOver.h"

namespace Tetris{

    class Game{
        public:
            Game();

        private:
            std::string drawArena();
            void gameloop();
            void generatePiece();
            void spawnNewPiece();
            void lockPiece();
            void movement();
            void snapDown();
            void moveDown();
            // void drawHead();
        
        private:
            Arena lockedArena;          // Stores pieces that have already fallen into place
            Arena movingPieceArena;     // Arena with only moving piece
            Collisions movementCheck;
            KeyRegister key;
            Score score;
            Colors colors;
            Scoreboard scoreboard;
            GameOver endGame;
            
            int posX = 3;
            int posY = 0;
            int rotation = 0;
            int pieceType = 0;
    };
};