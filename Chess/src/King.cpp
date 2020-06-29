#include "King.h"
#include <iostream>
#include <algorithm>

King::King()
{
    //ctor
}

bool King::movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]){

    if(color == "w"){ //FOR WHITE KING
        if(std::max(xS, x) - std::min(xS, x) <= 1 && std::max(yS, y) - std::min(yS, y) <= 1 && boardSpaces[x][y] != "white")
            return true;
        return false;


    }else{ //FOR BLACK KING
        if(std::max(xS, x) - std::min(xS, x) <= 1 && std::max(yS, y) - std::min(yS, y) <= 1 && boardSpaces[x][y] != "black")
            return true;
        return false;
    }

}

King::~King()
{
    //dtor
}
