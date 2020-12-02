#include <iostream>
#include <unistd.h>
#include "./lib/game.h"
#include "./lib/keyRegister.h"


using namespace std;

int main(){
    Tetris::Game game;
    Tetris::KeyRegister key;

    game.generatePiece();

    int count = 0;
    unsigned int microseconds = 10000;
    
    while (true)
    {
        system("clear");
        cout << game.drawArena() << endl;
        if (key.kbhit())
        {
            game.movement();
        }
        usleep(microseconds);
        if (count % 50 == 0)
        {
            game.moveDown();
        }
        count++;
    }
    return 0;
}