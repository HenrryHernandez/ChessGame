#ifndef KING_H
#define KING_H
#include <iostream>
#include "ChessPiece.h"

class King: public ChessPiece
{
    public:
        King();
        bool movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]);
        virtual ~King();

    protected:

    private:
};

#endif // KING_H
