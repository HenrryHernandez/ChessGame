#include "Pawn.h"
#include <iostream>

Pawn::Pawn()
{
    //ctor
}

bool Pawn::movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]){

    if(color == "w"){ //FOR WHITE PAWNS
        if(y == yS + 1 && xS == x && boardSpaces[x][y] == "empty"){
            return true;
        }else if(y == yS + 1 && (xS == x + 1 || xS == x - 1) && boardSpaces[x][y] == "black"){
            return true;
        }


    }else{ //FOR BLACK PAWNS
        if(y == yS - 1 && xS == x && boardSpaces[x][y] == "empty"){
            return true;
        }else if(y == yS - 1 && (xS == x + 1 || xS == x - 1) && boardSpaces[x][y] == "white"){
            return true;
        }
    }

}

Pawn::~Pawn()
{
    //dtor
}
