//
// Created by sanpi on 12/7/2023.
//

#ifndef FINAL_PROJECT_CS3520_SNAKECONTROLLER_H
#define FINAL_PROJECT_CS3520_SNAKECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "imgui.h"
#include "imgui-SFML.h"

/*
 * The plan was to add Snake as an additional game but ran out of time and
 * was not able to complete either Galaga or Snake
 */
class SnakeController {
private:
    sf::RenderWindow& window;
    Food food;
    Snake snake;
    bool showPopup;
    float blocksize;

    //wasn't able to get this working.
    //void renderPopup();
    void handleCollisions();
    void respawnFood();
public:
    SnakeController(sf::RenderWindow& window);

    void handleInput();
    void update(sf::Time deltaTime);
    void render();


};


#endif //FINAL_PROJECT_CS3520_SNAKECONTROLLER_H
