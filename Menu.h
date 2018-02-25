//
// Created by cepreu on 03.09.17.
//

#ifndef FLAPPYCUBE_MENU_H
#define FLAPPYCUBE_MENU_H

#include <SFML/Graphics.hpp>
#include "GameState.h"


class Menu {
public:
    Menu();
    GameState redraw(sf::RenderWindow &window);
    GameState  handleInput(sf::Event event);

private:
    unsigned int activeItem = 0;
    std::vector<std::string> items;
    sf::Font font;
};


#endif //FLAPPYCUBE_MENU_H
