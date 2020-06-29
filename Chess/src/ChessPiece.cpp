#include "ChessPiece.h"

ChessPiece::ChessPiece()
{
    //ctor
}

sf::Sprite* ChessPiece::getPieceSprite(std::string imagePath){
    std::string ip = imagePath;
    sf::Texture *pieceTexture = new sf::Texture();
    pieceTexture->loadFromFile(ip);

    sf::Sprite *pieceSprite = new sf::Sprite();
    pieceSprite->setTexture(*pieceTexture);
    return pieceSprite;
}

void ChessPiece::setId(int id){
    this->id = id;
}

int ChessPiece::getId(){
    return ChessPiece::id;
}

ChessPiece::~ChessPiece()
{
    //dtor
}
