#ifndef QUEEN_H
#define QUEEN_H
#include <iostream>
#include "ChessPiece.h"

class Queen: public ChessPiece
{
    public:
        Queen();
        bool movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]);
        virtual ~Queen();

    protected:

    private:
};

#endif // QUEEN_H
