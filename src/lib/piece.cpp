#include "piece.h"

namespace Tetris
{
    int Piece::getBlockOfPiece(int piece, int rotation, int xPosition, int yPosition){
        return pieces[piece][rotation][xPosition][yPosition];
    }
};