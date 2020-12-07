#pragma once

namespace Tetris{
    class KeyRegister
    {
        private:
        public: 
            enum Key{
                DOWN,
                LEFT,
                RIGHT,
                ROTATE_RIGHT,
                ROTATE_LEFT,
                INSTAFALL,
                UNKNOWN
            };
        
        public:
            static Key pressed_key(void);
            void clear(void);
            static char getch(void);
            int kbhit(void);
            
    };
};