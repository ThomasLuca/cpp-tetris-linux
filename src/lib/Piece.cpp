#include "Piece.h"

namespace Tetris
{
    bool Piece::getBlockOfPiece(int piece, int rotation, int xPosition, int yPosition){
        return pieces[piece][rotation][xPosition][yPosition];
    }
};