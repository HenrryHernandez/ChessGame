#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/Bishop.h"
#include "include/King.h"
#include "include/Knight.h"
#include "include/Pawn.h"
#include "include/Queen.h"
#include "include/Rook.h"


//FUNCTION JUST TO PRINT BOARD IN CONSOLE
void printBoard(std::string board[][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[j][i] == "white"){
                std::cout << "w ";
            }else if(board[j][i] == "black"){
                std::cout << "b ";
            }else{
                std::cout << "e ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void printBoardCodes(int board[][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
                std::cout << board[j][i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void printCodes(int codes[]){
    for(int i = 0; i < 32; i++){
        std::cout << i << " = " << codes[i] << std::endl;
    }
}

//GAME MAIN METHOD
int main()
{

    sf::RenderWindow window(sf::VideoMode(504, 504), "Chess Game");

    //BOARD
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("imagenes/board.png"))
        return EXIT_FAILURE;
    sf::Sprite boardSprite(boardTexture);

    //LOCATIONS ON BOARD
    sf::Vector2f boardXnY[8][8];
    int x = 40, y = 40;
    sf::Vector2f vec(x, y);
    for(int i = 0; i < 8; i++){
        vec.x = x + 56 * i;
        for(int j = 0; j < 8; j++){
            vec.y = y + 56 * j;
            boardXnY[i][j] = vec;
        }
    }

    //CONTROL FOR EMPTY, BLACK AND WHITE SPACES
    std::string occupiedSpaces[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            occupiedSpaces[i][j] = "empty";
        }
    }

    int boardCodes[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            boardCodes[i][j] = -1;
        }
    }

    //GAME OVER THING
    sf::Font font;
    font.loadFromFile("ovniFont.ttf");

    sf::Text winnerText;
    winnerText.setFont(font);
    winnerText.setCharacterSize(100);
    winnerText.setStyle(sf::Text::Regular);
    winnerText.setColor(sf::Color(0, 0, 0));
    winnerText.setPosition(25, 100);


    //WHITE PIECES
    Rook *rkW = new Rook();
    sf::Sprite *rkWSprite = rkW->getPieceSprite("imagenes/rookW.png");
    rkWSprite->setPosition(boardXnY[0][0]);
    occupiedSpaces[0][0] = "white";
    rkW->setId(0);
    boardCodes[0][0] = rkW->getId();

    Knight *knhW = new Knight();
    sf::Sprite *knhWSprite = knhW->getPieceSprite("imagenes/knightW.png");
    knhWSprite->setPosition(boardXnY[1][0]);
    occupiedSpaces[1][0] = "white";
    knhW->setId(1);
    boardCodes[1][0] = knhW->getId();

    Bishop *bshW = new Bishop();
    sf::Sprite *bshWSprite = bshW->getPieceSprite("imagenes/bishopW.png");
    bshWSprite->setPosition(boardXnY[2][0]);
    occupiedSpaces[2][0] = "white";
    bshW->setId(2);
    boardCodes[2][0] = bshW->getId();

    King *kingW = new King();
    sf::Sprite *kingWSprite = kingW->getPieceSprite("imagenes/kingW.png");
    kingWSprite->setPosition(boardXnY[3][0]);
    occupiedSpaces[3][0] = "white";
    kingW->setId(3);
    boardCodes[3][0] = kingW->getId();

    Queen *queenW = new Queen();
    sf::Sprite *queenWSprite = queenW->getPieceSprite("imagenes/queenW.png");
    queenWSprite->setPosition(boardXnY[4][0]);
    occupiedSpaces[4][0] = "white";
    queenW->setId(4);
    boardCodes[4][0] = queenW->getId();

    Bishop *bshWW = new Bishop();
    sf::Sprite *bshWWSprite = bshWW->getPieceSprite("imagenes/bishopW.png");
    bshWWSprite->setPosition(boardXnY[5][0]);
    occupiedSpaces[5][0] = "white";
    bshWW->setId(5);
    boardCodes[5][0] = bshWW->getId();

    Knight *knhWW = new Knight();
    sf::Sprite *knhWWSprite = knhWW->getPieceSprite("imagenes/knightW.png");
    knhWWSprite->setPosition(boardXnY[6][0]);
    occupiedSpaces[6][0] = "white";
    knhWW->setId(6);
    boardCodes[6][0] = knhWW->getId();

    Rook *rkWW = new Rook();
    sf::Sprite *rkWWSprite = rkWW->getPieceSprite("imagenes/rookW.png");
    rkWWSprite->setPosition(boardXnY[7][0]);
    occupiedSpaces[7][0] = "white";
    rkWW->setId(7);
    boardCodes[7][0] = rkWW->getId();


    //ARRAYS OF SPRITE FOR WHITE PIECES
    sf::Sprite *piecesWArray[8] = {rkWSprite, knhWSprite, bshWSprite, kingWSprite, queenWSprite, bshWWSprite, knhWWSprite, rkWWSprite};
    //sf::Sprite *piecesWArray[8] = {rkWSprite, rkWWSprite, knhWSprite, knhWWSprite, bshWSprite, bshWWSprite, kingWSprite, queenWSprite};

    //ARRAYS OF SPRITE FOR WHITE PAWNS
    sf::Sprite *pawnsWArray[8];
    Pawn *pawnsWInstances[8];
    //Pawn *pawnW = new Pawn();
    for(int i = 0; i < 8; i++){
        Pawn *pawnW = new Pawn();
        sf::Sprite *pawnWSprite = pawnW->getPieceSprite("imagenes/pawnW.png");
        pawnWSprite->setPosition(boardXnY[i][1]);
        occupiedSpaces[i][1] = "white";
        pawnsWArray[i] = pawnWSprite;
        pawnW->setId(i + 8);
        pawnsWInstances[i] = pawnW;
        boardCodes[i][1] = pawnW->getId();
    }



    //BLACK PIECES
    Rook *rkB = new Rook();
    sf::Sprite *rkBSprite = rkB->getPieceSprite("imagenes/rookB.png");
    rkBSprite->setPosition(boardXnY[0][7]);
    occupiedSpaces[0][7] = "black";
    rkB->setId(16);
    boardCodes[0][7] = rkB->getId();

    Knight *knhB = new Knight();
    sf::Sprite *knhBSprite = knhB->getPieceSprite("imagenes/knightB.png");
    knhBSprite->setPosition(boardXnY[1][7]);
    occupiedSpaces[1][7] = "black";
    knhB->setId(17);
    boardCodes[1][7] = knhB->getId();

    Bishop *bshB = new Bishop();
    sf::Sprite *bshBSprite = bshB->getPieceSprite("imagenes/bishopB.png");
    bshBSprite->setPosition(boardXnY[2][7]);
    occupiedSpaces[2][7] = "black";
    bshB->setId(18);
    boardCodes[2][7] = bshB->getId();

    King *kingB = new King();
    sf::Sprite *kingBSprite = kingB->getPieceSprite("imagenes/kingB.png");
    kingBSprite->setPosition(boardXnY[3][7]);
    occupiedSpaces[3][7] = "black";
    kingB->setId(19);
    boardCodes[3][7] = kingB->getId();

    Queen *queenB = new Queen();
    sf::Sprite *queenBSprite = queenB->getPieceSprite("imagenes/queenB.png");
    queenBSprite->setPosition(boardXnY[4][7]);
    occupiedSpaces[4][7] = "black";
    queenB->setId(20);
    boardCodes[4][7] = queenB->getId();

    Bishop *bshBB = new Bishop();
    sf::Sprite *bshBBSprite = bshBB->getPieceSprite("imagenes/bishopB.png");
    bshBBSprite->setPosition(boardXnY[5][7]);
    occupiedSpaces[5][7] = "black";
    bshBB->setId(21);
    boardCodes[5][7] = bshBB->getId();

    Knight *knhBB = new Knight();
    sf::Sprite *knhBBSprite = knhBB->getPieceSprite("imagenes/knightB.png");
    knhBBSprite->setPosition(boardXnY[6][7]);
    occupiedSpaces[6][7] = "black";
    knhBB->setId(22);
    boardCodes[6][7] = knhBB->getId();

    Rook *rkBB = new Rook();
    sf::Sprite *rkBBSprite = rkBB->getPieceSprite("imagenes/rookB.png");
    rkBBSprite->setPosition(boardXnY[7][7]);
    occupiedSpaces[7][7] = "black";
    rkBB->setId(23);
    boardCodes[7][7] = rkBB->getId();


    //ARRAYS OF SPRITE FOR BLACK PIECES
    sf::Sprite *piecesBArray[8] = {rkBSprite, knhBSprite, bshBSprite, kingBSprite, queenBSprite, bshBBSprite, knhBBSprite, rkBBSprite};
    //sf::Sprite *piecesBArray[8] = {rkBSprite, rkBBSprite, knhBSprite, knhBBSprite, bshBSprite, bshBBSprite, kingBSprite, queenBSprite};

    //ARRAYS OF SPRITE FOR BLACK PAWNS
    sf::Sprite *pawnsBArray[8];
    Pawn *pawnsBInstances[8];
    //Pawn *pawnB = new Pawn();
    for(int i = 0; i < 8; i++){
        Pawn *pawnB = new Pawn();
        sf::Sprite *pawnBSprite = pawnB->getPieceSprite("imagenes/pawnB.png");
        pawnBSprite->setPosition(boardXnY[i][6]);
        occupiedSpaces[i][6] = "black";
        pawnsBArray[i] = pawnBSprite;
        pawnB->setId(i + 24);
        pawnsBInstances[i] = pawnB;
        boardCodes[i][6] = pawnB->getId();
    }

    //PRINT THE BOARD
    printBoard(occupiedSpaces);
    printBoardCodes(boardCodes);


    //CONTROL VARIABLES FOR THE GAME LOOP
    bool ableSaveState = true;
    int xState = 0;
    int yState = 0;
    bool buttonPressedBefore = false;
    int spriteState = 0;
    std::string spriteIs = "n";
    int piecesCode[32];
    for(int i = 0; i < 32; i++)
        piecesCode[i] = 1;
    bool whiteTurn = true;
    bool blackTurn = false;

    //THIS IS VERY INEFFICIENT BECAUSE I'VE PREVIOUSLY DEFINED THE SAME BUT WITH SEPARATE ARRAYS.
    sf::Sprite *piecesArrayRepeated[32];
    for(int i = 0; i < 8; i++){
        piecesArrayRepeated[i] = piecesWArray[i];
        piecesArrayRepeated[i + 8] = pawnsWArray[i];
        piecesArrayRepeated[i + 16] = piecesBArray[i];
        piecesArrayRepeated[i + 24] = pawnsBArray[i];
    }

    //GAME LOOP
    while (window.isOpen())
    {

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) //IF WE CLICK ON A PIECE
        {
            //HERE WE CHECK WHAT PIECE OR PAWN IS CHOSEN
            if(!buttonPressedBefore){
                for(int i = 0; i < 8; i++){
                    if(pawnsWArray[i]->getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
                       && spriteIs == "n" && whiteTurn){
                            spriteState = i;
                            spriteIs = "pawnsW";
                       }else if(piecesWArray[i]->getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
                       && spriteIs == "n" && whiteTurn){
                            spriteState = i;
                            spriteIs = "pieceW";
                       }else if(pawnsBArray[i]->getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
                       && spriteIs == "n" && blackTurn){
                            spriteState = i;
                            spriteIs = "pawnsB";
                       }else if(piecesBArray[i]->getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
                       && spriteIs == "n"  && blackTurn){
                            spriteState = i;
                            spriteIs = "pieceB";
                       }
                }
            }

            buttonPressedBefore = true;

            if(spriteIs == "pawnsW"){
                if(ableSaveState){
                    xState = pawnsWArray[spriteState]->getPosition().x;
                    yState = pawnsWArray[spriteState]->getPosition().y;
                }
                ableSaveState = false;
                pawnsWArray[spriteState]->setPosition(sf::Mouse::getPosition(window).x - 15, sf::Mouse::getPosition(window).y - 15);

            }else if(spriteIs == "pieceW"){
                if(ableSaveState){
                    xState = piecesWArray[spriteState]->getPosition().x;
                    yState = piecesWArray[spriteState]->getPosition().y;
                }
                ableSaveState = false;
                piecesWArray[spriteState]->setPosition(sf::Mouse::getPosition(window).x - 15, sf::Mouse::getPosition(window).y - 15);

            }else if(spriteIs == "pawnsB"){
                if(ableSaveState){
                    xState = pawnsBArray[spriteState]->getPosition().x;
                    yState = pawnsBArray[spriteState]->getPosition().y;
                }
                ableSaveState = false;
                pawnsBArray[spriteState]->setPosition(sf::Mouse::getPosition(window).x - 15, sf::Mouse::getPosition(window).y - 15);

            }else if(spriteIs == "pieceB"){
                if(ableSaveState){
                    xState = piecesBArray[spriteState]->getPosition().x;
                    yState = piecesBArray[spriteState]->getPosition().y;
                }
                ableSaveState = false;
                piecesBArray[spriteState]->setPosition(sf::Mouse::getPosition(window).x - 15, sf::Mouse::getPosition(window).y - 15);

            } //HERE WE CHECK WHAT PIECE OR PAWN IS CHOSEN - END


        }else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonPressedBefore) //IF WE RELEASE THE PIECE
        {

            int stateXReleased = (sf::Mouse::getPosition(window).x - 28) / 56;
            int stateYReleased = (sf::Mouse::getPosition(window).y -28) / 56;
            xState = (xState -28) / 56;
            yState = (yState -28) / 56;

            if(spriteIs == "pawnsW"){ //CONDITIONS FOR WHITE PAWNS
                if(pawnsWInstances[spriteState]->movementAllowed("w", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                    if(occupiedSpaces[stateXReleased][stateYReleased] == "black"){
                        piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                        piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                    }
                    boardCodes[stateXReleased][stateYReleased] = pawnsWInstances[spriteState]->getId();
                    boardCodes[xState][yState] = -1;
                    pawnsWArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                    occupiedSpaces[stateXReleased][stateYReleased] = "white";
                    occupiedSpaces[xState][yState] = "empty";
                    whiteTurn = false;
                    blackTurn = true;
                }else{
                    pawnsWArray[spriteState]->setPosition(boardXnY[xState][yState]);
                }
                printBoard(occupiedSpaces);
                printBoardCodes(boardCodes);
                printCodes(piecesCode);


            }else if(spriteIs == "pieceW"){ //CONDITIONS FOR WHITE PIECES
                switch(spriteState){

                    case 0: //LEFT WHITE ROOK

                        if(rkW->movementAllowed("w", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "black"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = rkW->getId();
                            boardCodes[xState][yState] = -1;
                            piecesWArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "white";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = false;
                            blackTurn = true;
                        }else{
                            piecesWArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 1: //LEFT WHITE KNIGHT

                        if(knhW->movementAllowed("w", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "black"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = knhW->getId();
                            boardCodes[xState][yState] = -1;
                            piecesWArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "white";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = false;
                            blackTurn = true;
                        }else{
                            piecesWArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 2: //LEFT WHITE BISHOP

                        if(bshW->movementAllowed("w", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "black"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = bshW->getId();
                            boardCodes[xState][yState] = -1;
                            piecesWArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "white";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = false;
                            blackTurn = true;
                        }else{
                            piecesWArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 3: //WHITE QUEEN

                        if(queenW->movementAllowed("w", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "black"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = queenW->getId();
                            boardCodes[xState][yState] = -1;
                            piecesWArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "white";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = false;
                            blackTurn = true;
                        }else{
                            piecesWArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 4: //WHITE KING

                        if(kingW->movementAllowed("w", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "black"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = kingW->getId();
                            boardCodes[xState][yState] = -1;
                            piecesWArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "white";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = false;
                            blackTurn = true;
                        }else{
                            piecesWArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 5: //RIGHT WHITE BISHOP

                        if(bshWW->movementAllowed("w", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "black"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = bshWW->getId();
                            boardCodes[xState][yState] = -1;
                            piecesWArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "white";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = false;
                            blackTurn = true;
                        }else{
                            piecesWArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 6: //RIGHT WHITE KNIGHT

                        if(knhWW->movementAllowed("w", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "black"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = knhWW->getId();
                            boardCodes[xState][yState] = -1;
                            piecesWArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "white";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = false;
                            blackTurn = true;
                        }else{
                            piecesWArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 7: //RIGHT WHITE ROOK

                        if(rkWW->movementAllowed("w", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "black"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = rkWW->getId();
                            boardCodes[xState][yState] = -1;
                            piecesWArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "white";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = false;
                            blackTurn = true;
                        }else{
                            piecesWArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                }


            }else if(spriteIs == "pawnsB"){ //CONDITIONS FOR BLACK PAWNS
                if(pawnsBInstances[spriteState]->movementAllowed("b", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                    if(occupiedSpaces[stateXReleased][stateYReleased] == "white"){
                        piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                        piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                    }
                    boardCodes[stateXReleased][stateYReleased] = pawnsBInstances[spriteState]->getId();
                    boardCodes[xState][yState] = -1;
                    pawnsBArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                    occupiedSpaces[stateXReleased][stateYReleased] = "black";
                    occupiedSpaces[xState][yState] = "empty";
                    whiteTurn = true;
                    blackTurn = false;
                }else{
                    pawnsBArray[spriteState]->setPosition(boardXnY[xState][yState]);
                }
                printBoard(occupiedSpaces);
                printBoardCodes(boardCodes);
                printCodes(piecesCode);


            }else if(spriteIs == "pieceB"){ //CONDITIONS FOR BLACK PIECES
                switch(spriteState){

                    case 0: //LEFT BLACK ROOK

                        if(rkB->movementAllowed("b", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "white"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = rkB->getId();
                            boardCodes[xState][yState] = -1;
                            piecesBArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "black";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = true;
                            blackTurn = false;
                        }else{
                            piecesBArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 1: //LEFT BLACK KNIGHT

                        if(knhB->movementAllowed("b", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "white"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = knhB->getId();
                            boardCodes[xState][yState] = -1;
                            piecesBArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "black";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = true;
                            blackTurn = false;
                        }else{
                            piecesBArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 2: //LEFT BLACK BISHOP

                        if(bshB->movementAllowed("b", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "white"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = bshB->getId();
                            boardCodes[xState][yState] = -1;
                            piecesBArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "black";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = true;
                            blackTurn = false;
                        }else{
                            piecesBArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        printBoardCodes(boardCodes);
                        printCodes(piecesCode);
                        break;

                    case 3: //BLACK KING

                        if(kingB->movementAllowed("b", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "white"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = kingB->getId();
                            boardCodes[xState][yState] = -1;
                            piecesBArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "black";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = true;
                            blackTurn = false;
                        }else{
                            piecesBArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 4: //BLACK QUEEN

                        if(queenB->movementAllowed("b", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "white"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = queenB->getId();
                            boardCodes[xState][yState] = -1;
                            piecesBArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "black";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = true;
                            blackTurn = false;
                        }else{
                            piecesBArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 5: //RIGHT BLACK BISHOP

                        if(bshBB->movementAllowed("b", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "white"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = bshBB->getId();
                            boardCodes[xState][yState] = -1;
                            piecesBArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "black";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = true;
                            blackTurn = false;
                        }else{
                            piecesBArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 6: //RIGHT BLACK KNIGHT

                        if(knhBB->movementAllowed("b", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "white"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = knhBB->getId();
                            boardCodes[xState][yState] = -1;
                            piecesBArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "black";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = true;
                            blackTurn = false;
                        }else{
                            piecesBArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                    case 7: //RIGHT BLACK ROOK

                        if(rkBB->movementAllowed("b", xState, yState, stateXReleased, stateYReleased, occupiedSpaces)){
                            if(occupiedSpaces[stateXReleased][stateYReleased] == "white"){
                                piecesArrayRepeated[boardCodes[stateXReleased][stateYReleased]]->setPosition(-100, -100);
                                piecesCode[boardCodes[stateXReleased][stateYReleased]] = 0;
                            }
                            boardCodes[stateXReleased][stateYReleased] = rkBB->getId();
                            boardCodes[xState][yState] = -1;
                            piecesBArray[spriteState]->setPosition(boardXnY[stateXReleased][stateYReleased]);
                            occupiedSpaces[stateXReleased][stateYReleased] = "black";
                            occupiedSpaces[xState][yState] = "empty";
                            whiteTurn = true;
                            blackTurn = false;
                        }else{
                            piecesBArray[spriteState]->setPosition(boardXnY[xState][yState]);
                        }
                        printBoard(occupiedSpaces);
                        break;

                }

            }

            buttonPressedBefore = false;
            spriteIs = "n";
            ableSaveState = true;

        }


        //EVENTS
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        //---JUST THE DRAWING THING---

        //PRINT BOARD
        window.clear(sf::Color(200, 200, 200));
        window.draw(boardSprite); //DRAW BOARD

        //CHECK IF ANY OF THE KINGS HAS DIED AND PRINT THE WINNER
        if(piecesWArray[3]->getPosition().x == -100){
            winnerText.setString("   BLACKS\nHAVE WON");
            window.draw(winnerText);
            whiteTurn = false;
            blackTurn = false;
        }else if(piecesBArray[3]->getPosition().x == -100){
            winnerText.setString("   WHITES\nHAVE WON");
            window.draw(winnerText);
            whiteTurn = false;
            blackTurn = false;
        }

        //PRINT THE PIECES
        for(int i = 0; i < 8; i++){
            if(piecesCode[i] == 1)
                window.draw(*piecesWArray[i]); //DRAW WHITE PIECES

            if(piecesCode[i + 8] == 1)
                window.draw(*pawnsWArray[i]); //DRAW WHITE PAWNS

            if(piecesCode[i + 16] == 1)
                window.draw(*piecesBArray[i]); //DRAW BLACK PIECES

            if(piecesCode[i + 24] == 1)
                window.draw(*pawnsBArray[i]); //DRAW BLACK PAWNS

        }


        window.display();

    }

    return EXIT_SUCCESS;

}
