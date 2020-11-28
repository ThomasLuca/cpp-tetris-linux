#include <cstdlib>
#include <unistd.h>
#include <termios.h>
#include <iostream>

#include "keyRegister.h"

namespace Tetris{
    
    // found on https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
    static struct termios old, current;

    KeyRegister::Key KeyRegister::pressed_key(void)
    {
        char key = getch();
        switch (key)
        {
        case 'z':
            return Key::UP;
        case 's':
            return Key::DOWN;
        case 'q':
            return Key::LEFT;
        case 'd':
            return Key::Right;
        case 'a':
            return Key::RotateLeft;
        case 'e':
            return Key::RotateRight;
        }
    }

    void KeyRegister::clear(void)
    {
        system("clear");
    }


    char KeyRegister::getch(void)
    { 
        char ch;
        tcgetattr(0, &old);
        current = old;
        current.c_lflag &= ~ICANON;
        current.c_lflag &= ~ECHO;
        tcsetattr(0, TCSANOW, &current);
        ch = getchar();
        tcsetattr(0, TCSANOW, &old);
        return ch;
    }
}
