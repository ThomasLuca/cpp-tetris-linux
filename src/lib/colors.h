#pragma once
#include <string>

namespace Tetris{
    class Colors
    {
    public:
        std::string setChar(int colorMoving, int colorLocked);
    private:
        void determineActivePiece(int colorMoving, int colorLocked);
    private:
        int color = 0;
    
    };
};