//
// Created by cepreu on 03.09.17.
//

#ifndef FLAPPYCUBE_GAME_H
#define FLAPPYCUBE_GAME_H


#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Menu.h"
#include "GameState.h"


class Game {
public:
    Game();

    void run();

private:
    void handleInput(sf::Event event);
    void redraw();
    GameState state = GameState::Menu;
    sf::RenderWindow window;
    sf::Time frameTime = sf::seconds(1.f/60.f);
    Level level;
    Menu menu;
};


#endif //FLAPPYCUBE_GAME_H
