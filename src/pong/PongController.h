//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_PONGCONTROLLER_H
#define FINAL_PROJECT_CS3520_PONGCONTROLLER_H

#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>
#include <cmath>
class PongController {
private:
    sf::RenderWindow& window;
    Ball* ball;
    Paddle* leftPaddle;
    Paddle* rightPaddle;
    int leftScore;
    int rightScore;
    sf::Font font;
    sf::Text leftScoreText;
    sf::Text rightScoreText;
    void updateScores();
public:
    PongController(sf::RenderWindow& window);

    void handleInput();
    void update(sf::Time deltaTime);
    void render();


};



#endif //FINAL_PROJECT_CS3520_PONGCONTROLLER_H
