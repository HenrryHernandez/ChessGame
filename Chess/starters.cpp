
sprintsAndThat(){
    // Load a sprite to display
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("imagenes/board.png"))
        return EXIT_FAILURE;
    sf::Sprite boardSprite(boardTexture);


    sf::Texture rookWLTexture;
    if (!rookWLTexture.loadFromFile("imagenes/rookW.png"))
        return EXIT_FAILURE;
    sf::Sprite rookWLSprite(rookWLTexture);
    rookWLSprite.setPosition(40, 40);


    sf::Texture knightWLTexture;
    if (!knightWLTexture.loadFromFile("imagenes/knightW.png"))
        return EXIT_FAILURE;
    sf::Sprite knightWLSprite(knightWLTexture);
    knightWLSprite.setPosition(95, 40);



    sf::Texture bishopWLTexture;
    if (!bishopWLTexture.loadFromFile("imagenes/bishopW.png"))
        return EXIT_FAILURE;
    sf::Sprite bishopWLSprite(bishopWLTexture);
    bishopWLSprite.setPosition(150, 40);



    sf::Texture kingWTexture;
    if (!kingWTexture.loadFromFile("imagenes/kingW.png"))
        return EXIT_FAILURE;
    sf::Sprite kingWSprite(kingWTexture);
    kingWSprite.setPosition(207, 40);



    sf::Texture queenWTexture;
    if (!queenWTexture.loadFromFile("imagenes/queenW.png"))
        return EXIT_FAILURE;
    sf::Sprite queenWSprite(queenWTexture);
    queenWSprite.setPosition(263, 40);



    sf::Texture bishopWRTexture;
    if (!bishopWRTexture.loadFromFile("imagenes/bishopW.png"))
        return EXIT_FAILURE;
    sf::Sprite bishopWRSprite(bishopWRTexture);
    bishopWRSprite.setPosition(320, 40);



    sf::Texture knightWRTexture;
    if (!knightWRTexture.loadFromFile("imagenes/knightW.png"))
        return EXIT_FAILURE;
    sf::Sprite knightWRSprite(knightWRTexture);
    knightWRSprite.setPosition(375, 40);



    sf::Texture rookWRTexture;
    if (!rookWRTexture.loadFromFile("imagenes/rookW.png"))
        return EXIT_FAILURE;
    sf::Sprite rookWRSprite(rookWRTexture);
    rookWRSprite.setPosition(435, 40);


    sf::Texture pawnWTexture;
    if (!pawnWTexture.loadFromFile("imagenes/pawnW.png"))
        return EXIT_FAILURE;
    sf::Sprite pw[8];//pawnWSprite(pawnWTexture);

    for(int i = 0; i < 8; i++)
    {
        p[i].y = 95;
    }
    p[7].x = 435;
    for(int i = 8 - 2; i >= 0; i--)
    {
        p[i].x = p[i + 1].x - 55;
    }

}
