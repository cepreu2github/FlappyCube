//
// Created by cepreu on 03.09.17.
//

#include "Game.h"
#include "GameConstants.h"


Game::Game() {
    // создаем окно
    window.create(sf::VideoMode(GameConstants::windowWidth, GameConstants::windowHeight), "Flappy Cube");
}

void Game::run() {
    sf::Clock clock;
    sf::Time elapsed_time_since_update = sf::Time::Zero;

    // игровой цикл
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            handleInput(event);
        }
        sf::Time elapsed_time = clock.restart();
        elapsed_time_since_update += elapsed_time;
        if(elapsed_time_since_update > frameTime) {
            elapsed_time_since_update -= frameTime;

            redraw();
        }
    }
}

void Game::handleInput(sf::Event event) {
    if(state == GameState::Menu){
        state = menu.handleInput(event);
        if (state == GameState::Game)
            level.reset();
    }
    if(state == GameState::Game)
        state = level.handleInput(event);
    if(state == GameState::Exit)
        window.close();
}

void Game::redraw() {
    if(state == GameState::Menu)
        state = menu.redraw(window);
    if(state == GameState::Game)
        state = level.redraw(window);
    if(state == GameState::Exit)
        window.close();
}