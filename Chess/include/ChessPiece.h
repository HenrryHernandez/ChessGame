#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <SFML/Graphics.hpp>
#include <iostream>


class ChessPiece
{
    public:
        ChessPiece();
        sf::Sprite *getPieceSprite(std::string imagePath);
        void setId(int id);
        int getId();
        virtual ~ChessPiece();

    protected:

    private:
        int id;

};

#endif // CHESSPIECE_H
