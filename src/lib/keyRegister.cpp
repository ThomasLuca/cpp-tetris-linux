#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
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
        case ' ':
            return Key::INSTAFALL;
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

    int KeyRegister::kbhit(void)
    {   // found on https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
        struct termios oldt, newt;
        int ch;
        int oldf;
 
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
        ch = getchar();
 
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            fcntl(STDIN_FILENO, F_SETFL, oldf);
 
        if(ch != EOF)
        {
            ungetc(ch, stdin);
            return 1;
        }
 
        return 0;
    }
}
