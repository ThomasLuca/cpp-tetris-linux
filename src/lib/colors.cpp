#include "colors.h"
#include <string>

namespace Tetris{
    std::string Colors::setChar(int colorMoving, int colorLocked){
        determineActivePiece(colorMoving, colorLocked);
        if (this->color == 0)
        {
            return ". ";
        } else {
            return "\033[;3" + std::to_string(this->color) + "m██\033[0m";
        }        
    }

    void Colors::determineActivePiece(int colorMoving, int colorLocked){
        if (!colorMoving)
        {
            this->color = colorLocked;
        } else {
            this->color = colorMoving;
        }
    }
};