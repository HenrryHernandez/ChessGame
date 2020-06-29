#include "Rook.h"
#include <iostream>

Rook::Rook()
{
    //ctor
}

bool Rook::movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]){

    int piecesCount = 0;

    if(color == "w"){ //FOR WHITE PIECES


        if(xS == x && yS != y){ //IF X MAINTAINS IT MEANS WE JUST MOVE UP OR DOWN
            if(y > yS){ //WE'RE MOVING DOWN
                if(boardSpaces[x][y] != "white"){

                    for(int i = yS + 1; i <= y; i++){
                        if(boardSpaces[x][i] != "empty")
                            piecesCount++;
                    }

                    if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                        return false;
                    return true;

                }
                return false;

            }else{ //WE'RE MOVING UP
                if(boardSpaces[x][y] != "white"){

                    for(int i = yS - 1; i >= y; i--){
                        if(boardSpaces[x][i] != "empty")
                            piecesCount++;
                    }

                    if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                        return false;
                    return true;

                }
                return false;

            }

        }else if(yS == y && xS != x){ //IF Y MAINTAINS IT MEANS WE JUST MOVE LEFT OR RIGHT
            if(x > xS){ //WE'RE MOVING RIGHT
                if(boardSpaces[x][y] != "white"){

                    for(int i = xS + 1; i <= x; i++){
                        if(boardSpaces[i][y] != "empty")
                            piecesCount++;
                    }

                    if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                        return false;
                    return true;

                }
                return false;

            }else{ //WE'RE MOVING LEFT
                if(boardSpaces[x][y] != "white"){

                    for(int i = xS - 1; i >= x; i--){
                        if(boardSpaces[i][y] != "empty")
                            piecesCount++;
                    }

                    if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                        return false;
                    return true;

                }
                return false;
            }
        }

        return false;



    }else{ //FOR BLACK PIECES


        if(xS == x && yS != y){ //IF X MAINTAINS IT MEANS WE JUST MOVE UP OR DOWN
            if(y > yS){ //WE'RE MOVING DOWN
                if(boardSpaces[x][y] != "black"){

                    for(int i = yS + 1; i <= y; i++){
                        if(boardSpaces[x][i] != "empty")
                            piecesCount++;
                    }

                    if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                        return false;
                    return true;

                }
                return false;

            }else{ //WE'RE MOVING UP
                if(boardSpaces[x][y] != "black"){

                    for(int i = yS - 1; i >= y; i--){
                        if(boardSpaces[x][i] != "empty")
                            piecesCount++;
                    }

                    if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                        return false;
                    return true;

                }
                return false;

            }

        }else if(yS == y && xS != x){ //IF Y MAINTAINS IT MEANS WE JUST MOVE LEFT OR RIGHT
            if(x > xS){ //WE'RE MOVING RIGHT
                if(boardSpaces[x][y] != "black"){

                    for(int i = xS + 1; i <= x; i++){
                        if(boardSpaces[i][y] != "empty")
                            piecesCount++;
                    }

                    if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                        return false;
                    return true;

                }
                return false;

            }else{ //WE'RE MOVING LEFT
                if(boardSpaces[x][y] != "black"){

                    for(int i = xS - 1; i >= x; i--){
                        if(boardSpaces[i][y] != "empty")
                            piecesCount++;
                    }

                    if((piecesCount == 1 && boardSpaces[x][y] == "empty") || piecesCount > 1)
                        return false;
                    return true;

                }
                return false;
            }
        }

        return false;

    }

}

Rook::~Rook()
{
    //dtor
}
