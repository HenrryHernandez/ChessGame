#ifndef PAWN_H
#define PAWN_H
#include <iostream>
#include "ChessPiece.h"

class Pawn: public ChessPiece
{
    public:
        Pawn();
        bool movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]);
        virtual ~Pawn();

    protected:

    private:
};

#endif // PAWN_H
