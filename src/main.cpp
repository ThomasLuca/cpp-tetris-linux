#include <iostream>
#include "./lib/game.h"


using namespace std;


int main(){
    Tetris::Game game;
    cout << game.drawArena() << endl;

    return 0;
}