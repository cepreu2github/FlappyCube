//
// Created by cepreu on 03.09.17.
//

#ifndef FLAPPYCUBE_LEVEL_H
#define FLAPPYCUBE_LEVEL_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Tileset.h"
#include "GameState.h"
#include "GameConstants.h"


class Level {
public:
    Level();
    GameState redraw(sf::RenderWindow &window);
    GameState  handleInput(sf::Event event);
    void reset();

private:
    void createPipe();
    void calculatePipes();
    void calculateCube();
    void lose();
    void drawTexts(sf::RenderWindow &window);
    void drawGround(sf::RenderWindow &window);
    void drawPipes(sf::RenderWindow &window);
    void drawCube(sf::RenderWindow &window);
    void drawSprite(sf::RenderWindow &window, int number, int x, int y);
    Tileset tileset = Tileset("tileset.png", GameConstants::spriteSize,
                              GameConstants::spriteSize, sf::Color(109, 159, 185));
    double currentPosition;
    double currentAltitude;
    double effort;
    static constexpr double speed = GameConstants::speed;
    static const int spriteSize = GameConstants::spriteSize;
    static const int windowWidth = GameConstants::windowWidth;
    static const int windowHeight = GameConstants::windowHeight;
    sf::Color backgroundColor = sf::Color(63, 96, 113);
    struct Pipe{
        int position;
        int topBound;
        int bottomBound;
    };
    std::list<Pipe> pipes;
    bool isPause;
    bool isLose;
    sf::Font font;
    int highest;
    int last;

};


#endif //FLAPPYCUBE_LEVEL_H
