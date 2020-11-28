#pragma once

namespace Tetris{
    class KeyRegister
    {
        private:
            enum Key{
                UP,
                DOWN,
                LEFT,
                Right,
                RotateRight,
                RotateLeft,
            };

        public:
            Key pressed_key(void);
            void clear(void);
            char getch(void);
    };
};