#include "colors.h"

namespace Tetris{
    std::string Colors::setChar(int colorMoving, int colorLocked){
        determineActivePiece(colorMoving, colorLocked);
        switch (this->color)
        {
        case 0:
            return ". ";
        case 1:
            return "\033[;31m██\033[0m";
        case 2:
            return "\033[;32m██\033[0m";
        case 3:
            return "\033[;33m██\033[0m";
        case 4:
            return "\033[;34m██\033[0m";
        case 5:
            return "\033[;35m██\033[0m";
        case 6:
            return "\033[;36m██\033[0m";
        case 7:
            return "\033[;37m██\033[0m";
        default:
            return "\033[;32m██\033[0m";
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