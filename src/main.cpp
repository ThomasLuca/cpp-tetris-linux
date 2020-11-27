#include <iostream>
#include "./lib/piece.h"
#include "./lib/arena.h"


using namespace std;

void testPieces(){
    Tetris::Piece pieces;
    int typeOfPiece = 3;
    int position = 1;
    for (unsigned int  i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
        {
            if (pieces.getBlockOfPiece(typeOfPiece, position, i, j))
            {
                cout << "\033[;32m██\033[0m"; //32m = green foreground; 0m = transparent background
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

void testArena(){
    Tetris::Arena arena;
    arena.createArena();
    int pieceType = 4;
    int pieceRotation = 2;
    arena.lockPiece(0, 3, pieceType, pieceRotation);

    for (unsigned int i = 0; i < 21; i++)
    {
        for (unsigned int j = 0; j < 10; j++)
        {
            if (arena.getPoint(i, j))
            {
                cout << "\033[;32m██\033[0m";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main(){
    testArena();
    return 0;
}