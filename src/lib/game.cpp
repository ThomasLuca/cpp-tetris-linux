#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <unistd.h>
#include "keyRegister.h"
#include "game.h"



namespace Tetris{

    Game::Game(){
        lockedArena.createArena();
        movementCheck.initArena(&movingPieceArena, &lockedArena);
        scoreboard.innitScoreboard();
        gameloop();
    }

    void Game::gameloop(){
        generatePiece();
        int count = 0;
        unsigned int microseconds = 10000;
        bool needsUpdate = true;
        while (!lockedArena.isGameOver())
        {
            if (needsUpdate)
            {
                system("clear");
                scoreboard.placeScore(score.getScore());
                scoreboard.printScoreboard();
                std::cout << drawArena() << std::endl;
                needsUpdate = false;
            }
            if (key.kbhit())
            {
                movement();
                needsUpdate = true;
            }
            usleep(microseconds);
            if (count % 50 == 0)
            {
                moveDown();
                needsUpdate = true;
            }
            count++;
        }
        endGame.init(score.getScore());
    }

    std::string Game::drawArena(){
        movingPieceArena.createArena();
        movingPieceArena.placePiece(posY, posX, pieceType, rotation);
        
        std::stringstream output;
        for (int i = 0; i < lockedArena.getHeight(); i++)
        {
            output <<  "\033[;97m█\033[0m";
            for (int j = 0; j < lockedArena.getWidth(); j++)
            {
                output << colors.setChar(movingPieceArena.getPoint(i, j), lockedArena.getPoint(i, j));
            }
            output <<  "\033[;97m█\033[0m" <<std::endl;
        }
        output <<  "\033[;97m██████████████████████\033[0m" <<std::endl;
        return output.str();
    }

    void Game::generatePiece(){
        srand (time(NULL));
        scoreboard.setNextPiece(rand() % 7);
    }
    void Game::movement(){
        KeyRegister::Key key;
        key = KeyRegister::pressed_key();
        if (key == KeyRegister::Key::DOWN) {
            moveDown();
        } else if (key == KeyRegister::Key::LEFT && movementCheck.isValidMovement(key)) {
            posX--;
        } else if (key == KeyRegister::Key::RIGHT && movementCheck.isValidMovement(key)) {
            posX++;
        } else if (key == KeyRegister::Key::ROTATE_LEFT && movementCheck.isValidMovement(key)) {
            rotation = (rotation + 3) % 4;
        } else if (key == KeyRegister::Key::ROTATE_RIGHT && movementCheck.isValidMovement(key)) {
            rotation = (rotation + 1) % 4;
        } else if (key == KeyRegister::Key::INSTAFALL){
            snapDown();
        }
    }

    void Game::moveDown(){
        if(movementCheck.isValidMovement(KeyRegister::Key::DOWN)){
            posY++;
        } else {
            lockPiece();
            spawnNewPiece();
        }
    }

    void Game::snapDown(){
        while (movementCheck.isValidMovement(KeyRegister::Key::DOWN))
        {
            posY++;
            movingPieceArena.createArena();
            movingPieceArena.placePiece(posY, posX, pieceType, rotation);
        }
        lockPiece();
        spawnNewPiece();
    }

    void Game::lockPiece(){
        for (int i = posY; i < posY + 4; i++)
        {
            for (int j = posX; j < posX + 4; j++)
            {
                if (movingPieceArena.getPoint(i, j))
                {
                    lockedArena.setPoint(i, j, movingPieceArena.getPoint(i, j));
                }
            }
        }
        score.addToScore(lockedArena.checkClearLine(posY));
    }

    void Game::spawnNewPiece(){
        this->posX = 3;
        this->posY = 0;
        this->rotation = 0;
        this->pieceType = scoreboard.getNextPiece();
        generatePiece();
    }
};