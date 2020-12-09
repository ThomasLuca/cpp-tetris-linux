#include "score.h"

namespace Tetris{
    void Score::addToScore(int rows){
        int amount = 0;
        switch (rows)
        {
        case 1:
            amount = 50;
            break;
        case 2:
            amount = 125;
            break;
        case 3:
            amount = 200;
            break;
        case 4:
            amount = 275;
            break;
        default:
            amount = 0;
            break;
        }
        addPoints(amount);
    }

    void Score::addPoints(int amount){
        score += amount;
    }

    int Score::getScore(){
        return this->score;
    }
};