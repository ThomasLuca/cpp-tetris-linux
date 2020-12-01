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
        lockedArena.createArena();
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
        if (key == KeyRegister::Key::DOWN && isValidMovementDown()) {
            moveDown();
        } else if (key == KeyRegister::Key::LEFT && isValidMovementDown()) {
            POS_X--;
        } else if (key == KeyRegister::Key::RIGHT && isValidMovementDown()) {
            POS_X++;
        } else if (key == KeyRegister::Key::ROTATE_LEFT && isValidMovementDown()) {
            ROTATION = (ROTATION + 3) % 4;
        } else if (key == KeyRegister::Key::ROTATE_RIGHT && isValidMovementDown()) {
            ROTATION = (ROTATION + 1) % 4;
        }
    }

    void Game::moveDown(){
        POS_Y++;
    }

    bool Game::isValidMovementDown(){
        bool isValid = false;
        for (int i = 0; i < lockedArena.getHeight(); i++)
        {
            for (int j = 0; j < movingPieceArena.getWidth(); j++)
            {
                if (movingPieceArena.getPoint(i, j))
                {
                    if (lockedArena.getPoint(i+1, j) || i == lockedArena.getHeight() - 1)
                    {
                        isValid = false;
                        break;
                    } else {
                        isValid = true;
                    }
                }
            }
        }
        return isValid;
    }
};