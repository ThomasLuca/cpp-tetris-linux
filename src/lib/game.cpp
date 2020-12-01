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
        } else if (key == KeyRegister::Key::LEFT && isValidMovementLeft()) {
            POS_X--;
        } else if (key == KeyRegister::Key::RIGHT && isValidMovementRight()) {
            POS_X++;
        } else if (key == KeyRegister::Key::ROTATE_LEFT && isValidMovementDown() && isValidMovementLeft() && isValidMovementRight()) {
            ROTATION = (ROTATION + 3) % 4;
        } else if (key == KeyRegister::Key::ROTATE_RIGHT && isValidMovementDown() && isValidMovementLeft() && isValidMovementRight()) {
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
            for (int j = 0; j < lockedArena.getWidth(); j++)
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

    bool Game::isValidMovementLeft(){
        int count = 0;
        for (int i = 0; i < lockedArena.getHeight(); i++)
        {
            for (int j = 0; j < lockedArena.getWidth(); j++)
            {
                if (movingPieceArena.getPoint(i, j))
                {
                    if (j == 0)
                    {
                        count++;
                    }
                }
            }
        }
        bool isValid = (count >= 1) ? false : true;
        return isValid;
    }

    bool Game::isValidMovementRight(){
        // bool isValid = false;
        int count = 0;
        for (int i = 0; i < lockedArena.getHeight(); i++)
        {
            for (int j = 0; j < lockedArena.getWidth(); j++)
            {
                if (movingPieceArena.getPoint(i, j))
                {
                    if (j == lockedArena.getWidth() - 1)
                    {
                        count++;
                    }
                }
            }
        }
        bool isValid = (count >= 1) ? false : true;
        return isValid;
    }
};