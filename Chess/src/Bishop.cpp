#include "Bishop.h"
#include <iostream>
#include <algorithm>

Bishop::Bishop()
{
    //ctor
}

bool Bishop::movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]){

    int piecesCount = 0;

    if(color == "w"){ //FOR WHITE PIECES
        if(xS > x && yS > y && xS - x == yS - y){ //GOING LEFT-UP
            if(boardSpaces[x][y] != "white"){

                for(int i = 1; i <= xS - x; i++){
                    if(boardSpaces[xS - i][yS - i] != "empty")
                        piecesCount++;
                }

                if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                    return false;
                return true;

            }
            return false;

        }else if(xS < x && yS > y && x - xS == yS - y){ //GOING RIGHT-UP
            if(boardSpaces[x][y] != "white"){

                for(int i = 1; i <= x - xS; i++){
                    if(boardSpaces[xS + i][yS - i] != "empty")
                        piecesCount++;
                }

                if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                    return false;
                return true;

            }
            return false;

        }else if(xS < x && yS < y && x - xS == y - yS){ //GOING RIGHT-DOWN
            if(boardSpaces[x][y] != "white"){

                for(int i = 1; i <= x - xS; i++){
                    if(boardSpaces[xS + i][yS + i] != "empty")
                        piecesCount++;
                }

                if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                    return false;
                return true;

            }
            return false;

        }else if(xS > x && yS < y && xS - x == y - yS){ //GOING LEFT-DOWN
            if(boardSpaces[x][y] != "white"){

                for(int i = 1; i <= xS - x; i++){
                    if(boardSpaces[xS - i][yS + i] != "empty")
                        piecesCount++;
                }

                if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                    return false;
                return true;

            }
            return false;

        }

        return false;



    }else{//FOR BLACK PIECES
        if(xS > x && yS > y && xS - x == yS - y){ //GOING LEFT-UP
            if(boardSpaces[x][y] != "black"){

                for(int i = 1; i <= xS - x; i++){
                    if(boardSpaces[xS - i][yS - i] != "empty")
                        piecesCount++;
                }

                if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                    return false;
                return true;

            }
            return false;

        }else if(xS < x && yS > y && x - xS == yS - y){ //GOING RIGHT-UP
            if(boardSpaces[x][y] != "black"){

                for(int i = 1; i <= x - xS; i++){
                    if(boardSpaces[xS + i][yS - i] != "empty")
                        piecesCount++;
                }

                if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                    return false;
                return true;

            }
            return false;

        }else if(xS < x && yS < y && x - xS == y - yS){ //GOING RIGHT-DOWN
            if(boardSpaces[x][y] != "black"){

                for(int i = 1; i <= x - xS; i++){
                    if(boardSpaces[xS + i][yS + i] != "empty")
                        piecesCount++;
                }

                if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                    return false;
                return true;

            }
            return false;

        }else if(xS > x && yS < y && xS - x == y - yS){ //GOING LEFT-DOWN
            if(boardSpaces[x][y] != "black"){

                for(int i = 1; i <= xS - x; i++){
                    if(boardSpaces[xS - i][yS + i] != "empty")
                        piecesCount++;
                }

                if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                    return false;
                return true;
            }
            return false;

        }

        return false;
    }

}

Bishop::~Bishop()
{
    //dtor
}
