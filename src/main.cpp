#include <iostream>
#include "./lib/Piece.h"

using namespace std;

int main(){
    Tetris::Piece pieces;
    int typeOfPiece = 3;
    int position = 1;
    for (unsigned int  i = 0; i < 4; i++)   // x-Position
    {
        for (unsigned int j = 0; j < 4; j++)    // y-Position
        {
            if (pieces.getBlockOfPiece(typeOfPiece, position, i, j))
            {
                cout << "█";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}