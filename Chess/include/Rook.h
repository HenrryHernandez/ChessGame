#ifndef ROOK_H
#define ROOK_H
#include <iostream>
#include "ChessPiece.h"

class Rook: public ChessPiece
{
    public:
        Rook();
        bool movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]);
        virtual ~Rook();

    protected:

    private:
};

#endif // ROOK_H
