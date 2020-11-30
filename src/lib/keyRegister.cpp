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
        case 's':
            return Key::DOWN;
        case 'q':
            return Key::LEFT;
        case 'd':
            return Key::RIGHT;
        case 'a':
            return Key::ROTATE_LEFT;
        case 'e':
            return Key::ROTATE_RIGHT;
        }
        return Key::UNKNOWN;
        
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
