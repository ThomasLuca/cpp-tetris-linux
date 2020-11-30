#include <iostream>
#include <unistd.h>
#include "./lib/game.h"


using namespace std;


int main(){
    Tetris::Game game;
    game.generatePiece();
    do
    {
        game.movement();
        system("clear");
        // game.moveDown();
        cout << game.drawArena() << endl;
        sleep(0.05);
    } while (true);
    

    return 0;
}