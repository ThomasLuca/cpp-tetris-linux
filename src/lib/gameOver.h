#pragma once
#include <string>

namespace Tetris{
    class GameOver
    {
    private:
        int score = 0;
        std::string crown = "\033[;33m\t|\\/\\/\\/|\n\t|______|\033[0m";
        std::string again = "Would you like to play again? (y/n): ";
        std::string userChoise = "";
    private:
        void printToTerminal();
        void decideNextStep();

    public:
        void init(int score);
    };
};