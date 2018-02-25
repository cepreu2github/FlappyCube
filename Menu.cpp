//
// Created by cepreu on 03.09.17.
//

#include "Menu.h"
#include "GameConstants.h"

Menu::Menu(){
    items.push_back("Start");
    items.push_back("Exit");
    font.loadFromFile("font.ttf");
}


GameState Menu::redraw(sf::RenderWindow &window) {
    window.clear(sf::Color(0, 0, 0));

    int startPositionY = window.getSize().y/2 - items.size()*GameConstants::fontSize;
    int startPositionX = window.getSize().x/2 - GameConstants::fontSize*3;
    for (int i=0; i < items.size(); i++) {
        sf::Text text;
        text.setFont(font);
        text.setString(items[i]);
        text.setCharacterSize(24);
        text.setPosition(startPositionX, startPositionY + GameConstants::fontSize * 2 * i);
        if (i == activeItem)
            text.setFillColor(sf::Color::Red);
        else
            text.setFillColor(sf::Color::White);
        window.draw(text);

    }

    window.display();

    return GameState::Menu;
}

GameState  Menu::handleInput(sf::Event event) {
    switch (event.key.code) {
        case sf::Keyboard::Up:
            if (activeItem>0)
                activeItem--;
            break;
        case sf::Keyboard::Down:
            if (activeItem<items.size()-1)
                activeItem++;
            break;
        case sf::Keyboard::Return:
            if (activeItem == 0)
                return GameState::Game;
            if (activeItem == 1)
                return GameState::Exit;
            break;
        default:
            break;
    }
    return GameState::Menu;
}