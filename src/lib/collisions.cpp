#include "collisions.h"

namespace Tetris
{
    void Collisions::initArena(Arena *mp, Arena *la){
        this->movingPieceArena = mp;
        this->lockedArena = la;
    }

    bool Collisions::isValidMovement(KeyRegister::Key key)
    {
        int count = 0;
        for (int i = 0; i < lockedArena->getHeight(); i++)
        {
            for (int j = 0; j < lockedArena->getWidth(); j++)
            {
                if (movingPieceArena->getPoint(i, j))
                {
                    switch (key)
                    {
                    case KeyRegister::Key::LEFT:
                        if (j == 0 || lockedArena->getPoint(i, j - 1))
                        {
                            count++;
                        }
                        break;
                    case KeyRegister::Key::RIGHT:
                        if (j == lockedArena->getWidth() - 1 || lockedArena->getPoint(i, j + 1))
                        {
                            count++;
                        }
                        break;
                    case KeyRegister::Key::DOWN:
                        if (lockedArena->getPoint(i + 1, j) || i == lockedArena->getHeight() - 1)
                        {
                            count++;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        bool isValid = (count >= 1) ? false : true;
        return isValid;
    }
}; // namespace Tetris