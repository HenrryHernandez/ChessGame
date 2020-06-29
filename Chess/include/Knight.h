#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include "ChessPiece.h"

class Knight: public ChessPiece
{
    public:
        Knight();
        bool movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]);
        virtual ~Knight();

    protected:

    private:
};

#endif // KNIGHT_H
