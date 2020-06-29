#include "Queen.h"
#include <iostream>

Queen::Queen()
{
    //ctor
}


bool Queen::movementAllowed(std::string color, int xS, int yS, int x, int y, std::string boardSpaces[][8]){

    int piecesCount = 0;


    if(color == "w"){ //FOR WHITE PIECES


        //-----ROOK LIKE MOVEMENTS-----

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


        //-----BISHOP LIKE MOVEMENTS-----

        else if(xS > x && yS > y && xS - x == yS - y){ //GOING LEFT-UP
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



    }else{ //FOR BLACK PIECES


        //-----ROOK LIKE MOVEMETS-----

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


        //-----BISHOP LIKE MOVEMENTS-----

        else if(xS > x && yS > y && xS - x == yS - y){ //GOING LEFT-UP
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

Queen::~Queen()
{
    //dtor
}
