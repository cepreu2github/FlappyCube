//
// Created by cepreu on 03.09.17.
//

#include "Tileset.h"


Tileset::Tileset(std::string filePath, int tileWidth, int tileHeight, sf::Color background) {
    sf::Image img;
    img.loadFromFile("tileset.png");
    img.createMaskFromColor(background);
    tilesetImage.loadFromImage(img);
    tilesetImage.setSmooth(false);
    int columns = tilesetImage.getSize().x / tileWidth;
    int rows = tilesetImage.getSize().y / tileHeight;

    for (int y = 0; y < rows; y++)
        for (int x = 0; x < columns; x++) {
            sf::Rect<int> rect;

            rect.top = y * tileHeight;
            rect.height = tileHeight;
            rect.left = x * tileWidth;
            rect.width = tileWidth;

            subRects.push_back(rect);
        }
}

sf::Sprite Tileset::getSprite(int tileNo) {
    sf::Sprite sprite;
    sprite.setTexture(tilesetImage);
    sprite.setTextureRect(subRects[tileNo]);
    return sprite;
}