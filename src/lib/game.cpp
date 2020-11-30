#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "game.h"
#include "keyRegister.h"


namespace Tetris{

    Game::Game(){
        drawArena();
    }

    std::string Game::drawArena(){
        arena.createArena();
        arena.placePiece(POS_Y, POS_X, pieceType, ROTATION);
        
        std::stringstream output;
        for (int i = 0; i < arena.getHeight(); i++)
        {
            for (int j = 0; j < arena.getWidth(); j++)
            {
                if (arena.getPoint(i, j))
                {
                    output << "\033[;32m██\033[0m";
                } else {
                    output << ". ";
                }
            }
            output << std::endl;
        }
        return output.str();
    }

    void Game::generatePiece(){
        srand (time(NULL));
        pieceType = rand() % 7;
    }
    void Game::movement(){
        KeyRegister::Key key;
        key = KeyRegister::pressed_key();
        if (key == KeyRegister::Key::DOWN) {
            moveDown();
        } else if (key == KeyRegister::Key::LEFT) {
            POS_X--;
        } else if (key == KeyRegister::Key::RIGHT) {
            POS_X++;
        } else if (key == KeyRegister::Key::ROTATE_LEFT) {
            ROTATION = (ROTATION + 3) % 4;
        } else if (key == KeyRegister::Key::ROTATE_RIGHT) {
            ROTATION = (ROTATION + 1) % 4;
        }
    }

    void Game::moveDown(){
        POS_Y++;
    }
};