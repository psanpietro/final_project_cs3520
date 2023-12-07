//
// Created by sanpi on 12/7/2023.
//

#include <iostream>
#include "SnakeController.h"

SnakeController::SnakeController(sf::RenderWindow& window)
        :food(window.getSize()), window(window), snake(window.getSize(), 100.0f), blocksize(16.f) {
    showPopup = false;
}

void SnakeController::handleCollisions() {
    //Collision seemed to be broken in the Snake class
    /*
    if (snake.checkCollision()) {
        showPopup = true;
    }
     */
}

void SnakeController::handleInput() {
    //the movement handling in the controller due to issue with the Snake class updating
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.getDirection() != Snake::Direction::Down) {
        snake.setDirection(Snake::Direction::Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.getDirection() != Snake::Direction::Up) {
        snake.setDirection(Snake::Direction::Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.getDirection() != Snake::Direction::Right) {
        snake.setDirection(Snake::Direction::Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.getDirection() != Snake::Direction::Left) {
        snake.setDirection(Snake::Direction::Right);
    }
}

void SnakeController::respawnFood() {
    food.respawn();
    // attempt to prevent food spawning on snake did not work
}

void SnakeController::update(sf::Time deltaTime) {
    //if (showPopup) {

    //} else {
        snake.update(deltaTime);
        handleCollisions();
        if (snake.getBody()[0] == food.getPosition()) {
            //should grow snake if head encounters food position.
            //snake.grow();
            respawnFood();
        }
    //}
}

void SnakeController::render() {
    window.clear();

    //Popup never worked and only caused crashing
    if (showPopup) {
        //std::cout<< "reached here" <<std::endl;
        //        renderPopup();
    } else {
        snake.render(window);
        //food gets drawn here because wanted to test it even drew at all before moving to Food class. Had issues.
        sf::RectangleShape foodBlock(sf::Vector2f(blocksize, blocksize));
        foodBlock.setPosition(food.getPosition().x * blocksize, food.getPosition().y * blocksize);
        window.draw(foodBlock);
    }

    window.display();
}

/*
 * Tried to use the built PopupModel from ImGUi but had issues because of the integrated nature of SFML and ImGUi that
 * most of what i was doing was using the integration and that caused Context issues wtihin ImGui that I was not
 * able to solve
void SnakeController::renderPopup() {
    ImGui::CreateContext();
    if (ImGui::BeginPopupModal("Game Over", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text("Thanks for playing!");

        if (ImGui::Button("Continue")) {
            // Continue playing with a new snake
            showPopup = false;
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }
}
 */