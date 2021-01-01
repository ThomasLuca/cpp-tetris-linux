#include "gameOver.h"
#include "game.h"
#include <iostream>
#include <string>

namespace Tetris{
    void GameOver::init(int score){
        this->score = score;
        this->printToTerminal();
    }
    void GameOver::printToTerminal(){
        system("clear");
        std::cout << crown << std::endl;
        std::cout << "\t  "+ std::to_string(score) + "\n" << std::endl;
        do
        {
            std::cout << again;
            std::cin >> this->userChoise;
        } while ((this->userChoise[0] != 'y') && (this->userChoise[0] != 'n'));
        decideNextStep();
    }

    void GameOver::decideNextStep()
    {
        if (userChoise[0] == 'y')
        {
            Game game;
        }
        else
        {
            exit(0);
        }
    }
};