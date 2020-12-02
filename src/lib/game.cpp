#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "game.h"
#include "keyRegister.h"


namespace Tetris{

    Game::Game(){
        lockedArena.createArena();
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
        if(isValidMovementDown()){
            POS_Y++;
        } else {
            lockPiece();
            spawnNewPiece();
        }
    }

    bool Game::isValidMovementDown(){
        int count = 0;
        for (int i = 0; i < lockedArena.getHeight(); i++)
        {
            for (int j = 0; j < lockedArena.getWidth(); j++)
            {
                if (movingPieceArena.getPoint(i, j))
                {
                    if (lockedArena.getPoint(i+1, j) || i == lockedArena.getHeight() - 1)
                    {
                        count++;
                    }
                }
            }
        }
        bool isValid = (count >= 1) ? false : true;
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
                    if (j == 0  || lockedArena.getPoint(i, j-1))
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
        int count = 0;
        for (int i = 0; i < lockedArena.getHeight(); i++)
        {
            for (int j = 0; j < lockedArena.getWidth(); j++)
            {
                if (movingPieceArena.getPoint(i, j))
                {
                    if (j == lockedArena.getWidth() - 1 || lockedArena.getPoint(i, j+1))
                    {
                        count++;
                    }
                }
            }
        }
        bool isValid = (count >= 1) ? false : true;
        return isValid;
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