//
// Created by cepreu on 04.09.17.
//

#ifndef FLAPPYCUBE_GAMECONSTANTS_H
#define FLAPPYCUBE_GAMECONSTANTS_H


#include <SFML/Graphics.hpp>

class GameConstants {
public:
    static const unsigned int windowWidth = 800;
    static const unsigned int windowHeight = 600;
    static const unsigned int fontSize = 24;
    static constexpr double speed = 1.;
    static constexpr double startAltitude = 300.0;
    static constexpr double pipesStart = 200.0;
    static const unsigned int spriteSize = 16;
    static const unsigned int groundSprite = 11;
    static const unsigned int topPipeLeft = 261;
    static const unsigned int topPipeRight = 262;
    static const unsigned int topPipeEndLeft = 300;
    static const unsigned int topPipeEndRight = 301;
    static const unsigned int bottomPipeLeft = 298;
    static const unsigned int bottomPipeRight = 299;
    static const unsigned int bottomPipeEndLeft = 259;
    static const unsigned int bottomPipeEndRight = 260;
    static const unsigned int cubeSpite = 273;
    static const unsigned int startPipeHeight = 300;
    static constexpr double pipeHeightScale = 0.01;
    static const unsigned int startPipesDistance = 200;
    static constexpr double pipeDistanceScale = 0.01;
    static constexpr double flyDownSpeed = 2.;
    static constexpr double flyUpSpeed = 2.;
    static constexpr double effortIncrement = 128.;
    static const int toward = 96;

};


#endif //FLAPPYCUBE_GAMECONSTANTS_H
