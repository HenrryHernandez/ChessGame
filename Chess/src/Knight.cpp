#include "Knight.h"
#include <iostream>

Knight::Knight()
{
    //ctor
}

bool Knight::movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]){

    if(color == "w"){ //FOR WHITE KNIGHT
        if((y == yS + 2 || y == yS - 2) && (xS == x + 1 || xS == x - 1) && (boardSpaces[x][y] == "empty" || boardSpaces[x][y] == "black")){
            return true;
        }else if((y == yS + 1 || y == yS - 1) && (xS == x + 2 || xS == x - 2) && (boardSpaces[x][y] == "empty" || boardSpaces[x][y] == "black")){
            return true;
        }


    }else{ //FOR BLACK KNIGHT
        if((y == yS + 2 || y == yS - 2) && (xS == x + 1 || xS == x - 1) && (boardSpaces[x][y] == "empty" || boardSpaces[x][y] == "white")){
            return true;
        }else if((y == yS + 1 || y == yS - 1) && (xS == x + 2 || xS == x - 2) && (boardSpaces[x][y] == "empty" || boardSpaces[x][y] == "white")){
            return true;
        }
    }

}

Knight::~Knight()
{
    //dtor
}
