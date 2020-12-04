#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "game.h"
#include "keyRegister.h"


namespace Tetris{

    Game::Game(){
        lockedArena.createArena();
        movementCheck.initArena(&movingPieceArena, &lockedArena);
    }

    std::string Game::drawArena(){
        movingPieceArena.createArena();
        movingPieceArena.placePiece(POS_Y, POS_X, pieceType, ROTATION);
        
        std::stringstream output;
        for (int i = 0; i < lockedArena.getHeight(); i++)
        {
            for (int j = 0; j < lockedArena.getWidth(); j++)
            {
                if (movingPieceArena.getPoint(i, j) || lockedArena.getPoint(i, j))
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
        } else if (key == KeyRegister::Key::LEFT && movementCheck.isValidMovement(key)) {
            POS_X--;
        } else if (key == KeyRegister::Key::RIGHT && movementCheck.isValidMovement(key)) {
            POS_X++;
        } else if (key == KeyRegister::Key::ROTATE_LEFT && movementCheck.isValidMovement(key)) {
            ROTATION = (ROTATION + 3) % 4;
        } else if (key == KeyRegister::Key::ROTATE_RIGHT && movementCheck.isValidMovement(key)) {
            ROTATION = (ROTATION + 1) % 4;
        }
    }

    void Game::moveDown(){
        if(movementCheck.isValidMovement(KeyRegister::Key::DOWN)){
            POS_Y++;
        } else {
            lockPiece();
            spawnNewPiece();
        }
    }

    void Game::lockPiece(){
        for (int i = 0; i < lockedArena.getHeight(); i++)
        {
            for (int j = 0; j < lockedArena.getWidth(); j++)
            {
                if (movingPieceArena.getPoint(i, j))
                {
                    lockedArena.setPoint(i, j);
                }
            }
        }
    }

    void Game::spawnNewPiece(){
        this->POS_X = 3;
        this->POS_Y = 0;
        this->ROTATION = 0;
        generatePiece();
    }
};