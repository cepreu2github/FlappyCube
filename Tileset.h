//
// Created by cepreu on 03.09.17.
//

#ifndef FLAPPYCUBE_TILESET_H
#define FLAPPYCUBE_TILESET_H

#include <SFML/Graphics.hpp>

class Tileset {
public:
    Tileset(std::string filePath, int tileWidth, int tileHeight, sf::Color background);

    sf::Sprite getSprite(int tileNo);

private:
    sf::Texture tilesetImage;
    std::vector<sf::Rect<int>> subRects;
};


#endif //FLAPPYCUBE_TILESET_H
