//
// Created by cepreu on 03.09.17.
//

#include "Level.h"
#include <stdlib.h>
#include <time.h>

Level::Level() {
    last = 0;
    highest = 0;
    font.loadFromFile("font.ttf");
    reset();
}

void Level::reset() {
    currentPosition = 0.0;
    currentAltitude = GameConstants::startAltitude;
    effort = -1.0;
    pipes.clear();
    srand (time(NULL));
    isPause = false;
    isLose = false;
    if (last > highest)
        highest = last;
}

void Level::drawSprite(sf::RenderWindow &window, int number, int x, int y) {
    sf::Sprite sprite = tileset.getSprite(number);
    sprite.setPosition(x, y);
    sprite.setColor(sf::Color(255, 255, 255, 255));
    window.draw(sprite);

}

void Level::drawGround(sf::RenderWindow &window) {
    int groundStart = - ((int) currentPosition) % spriteSize;
    for (int i = groundStart; i < windowWidth; i += spriteSize)
        drawSprite(window, GameConstants::groundSprite, i, windowHeight - spriteSize);
}

void Level::createPipe() {
    Pipe pipe;
    pipe.position = currentPosition + windowWidth;
    int pipeHeight = GameConstants::startPipeHeight - GameConstants::pipeHeightScale * currentPosition;
    pipe.topBound = rand() % (windowHeight - pipeHeight - spriteSize * 2) + 1;
    pipe.bottomBound = pipe.topBound + pipeHeight;
    pipes.push_back(pipe);
}

void Level::calculatePipes() {
    int pipesDistance = GameConstants::startPipesDistance - GameConstants::pipeDistanceScale * currentPosition;
    if (pipesDistance < spriteSize*2)
        pipesDistance = spriteSize*2;
    if (currentPosition >= GameConstants::pipesStart && pipes.empty())
        createPipe();
    if (!pipes.empty() && pipes.back().position + pipesDistance < currentPosition + windowWidth)
        createPipe();
    if (!pipes.empty() && pipes.front().position < currentPosition - spriteSize * 2)
        pipes.pop_front();
}

void Level::drawPipes(sf::RenderWindow &window) {
    for (std::list<Pipe>::iterator it=pipes.begin(); it != pipes.end(); ++it){
        Pipe pipe = *it;
        int position = pipe.position - currentPosition;
        for (int i = 0; i < pipe.topBound - spriteSize; i += spriteSize){
            drawSprite(window, GameConstants::topPipeLeft, position, i);
            drawSprite(window, GameConstants::topPipeRight, position + spriteSize, i);
        }
        drawSprite(window, GameConstants::topPipeEndLeft, position, pipe.topBound - spriteSize);
        drawSprite(window, GameConstants::topPipeEndRight, position + spriteSize, pipe.topBound - spriteSize);
        for (int i = pipe.bottomBound + spriteSize; i < windowHeight; i += spriteSize){
            drawSprite(window, GameConstants::bottomPipeLeft, position, i);
            drawSprite(window, GameConstants::bottomPipeRight, position + spriteSize, i);
        }
        drawSprite(window, GameConstants::bottomPipeEndLeft, position, pipe.bottomBound);
        drawSprite(window, GameConstants::bottomPipeEndRight, position + spriteSize, pipe.bottomBound);

    }
}

void Level::lose() {
    isPause = true;
    isLose = true;
    last = (int) currentPosition;
}

void Level::calculateCube() {
    if (effort > 0.0){
        currentAltitude -= GameConstants::flyUpSpeed;
        effort -= GameConstants::flyUpSpeed;
    } else {
        currentAltitude += GameConstants::flyDownSpeed;
    }
    int cubePosition = currentPosition + GameConstants::toward;
    for (std::list<Pipe>::iterator it=pipes.begin(); it != pipes.end(); ++it){
        Pipe pipe = *it;
        if (cubePosition + spriteSize >= pipe.position && cubePosition < pipe.position + spriteSize*2)
            if (currentAltitude <= pipe.topBound || currentAltitude + spriteSize > pipe.bottomBound){
                lose();
            }
    }
    if (currentAltitude >= windowHeight - spriteSize * 2){
        lose();
    }
}

void Level::drawCube(sf::RenderWindow &window) {
    drawSprite(window, GameConstants::cubeSpite, GameConstants::toward, currentAltitude);
}

void Level::drawTexts(sf::RenderWindow &window) {
    if (isLose){
        sf::Text text;
        text.setFont(font);
        std::string info = "GAME OVER\n";
        info += "Your score: " + std::to_string(last);
        info += "\nHighest score: " + std::to_string(highest);
        if (highest <= last){
            info += "\nYou made a new record!";
        }
        text.setString(info);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        text.setPosition(windowWidth/3, windowHeight/3);
        window.draw(text);

    } else if (isPause){
        sf::Text text;
        text.setFont(font);
        text.setString("PAUSE");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        text.setPosition(0, 0);
        window.draw(text);
    }
}

GameState Level::redraw(sf::RenderWindow &window) {
    if (!isPause){
        currentPosition += speed;
        calculateCube();
        calculatePipes();
    }
    window.clear(backgroundColor);
    drawCube(window);
    drawPipes(window);
    drawGround(window);
    drawTexts(window);
    window.display();
    return GameState::Game;
}

GameState Level::handleInput(sf::Event event) {
    switch (event.key.code) {
        case sf::Keyboard::Escape:
            return GameState::Menu;
            break;
        case sf::Keyboard::R:
            reset();
            break;
        case sf::Keyboard::P:
            if (event.type == sf::Event::KeyReleased && !isLose){
                if (isPause)
                    isPause = false;
                else
                    isPause = true;
            }
            break;
        case sf::Keyboard::Space:
            if (!isPause)
                effort += GameConstants::effortIncrement;
            break;
        default:
            break;
    }
    return GameState::Game;
}