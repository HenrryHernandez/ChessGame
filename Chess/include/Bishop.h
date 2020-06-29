#ifndef BISHOP_H
#define BISHOP_H
#include <iostream>
#include "ChessPiece.h"

class Bishop: public ChessPiece
{
    public:
        Bishop();
        bool movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]);
        virtual ~Bishop();

    protected:

    private:
};

#endif // BISHOP_H
