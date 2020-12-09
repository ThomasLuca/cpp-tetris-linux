#pragma once

namespace Tetris{
    class Score
    {
    private:
        int score = 0;    
    public:
        int getScore();
        void addToScore(int rows);
       
    private:
        void addPoints(int amount);

    };
};