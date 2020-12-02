#include <iostream>
#include <thread>
#include "./lib/game.h"
#include "./lib/keyRegister.h"


using namespace std;


int main(){
    Tetris::Game game;
    Tetris::KeyRegister key;

    game.generatePiece();
    while (true)
    {
        system("clear");
        cout << game.drawArena() << endl;
        if (key.kbhit())
        {
            game.movement();
        }
        game.moveDown();
        this_thread::sleep_for(1000ms);
    }
    return 0;
}