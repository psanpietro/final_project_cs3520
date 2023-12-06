//
// Created by sanpi on 12/6/2023.
//

#include "Paddle.h"


Paddle::Paddle(float startX, float startY) {
    shape.setSize(sf::Vector2f(10.f, 80.f));
    shape.setPosition(startX, startY - shape.getSize().y / 2.f);
    shape.setFillColor(sf::Color::White);
    speed = 200.f;
}

void Paddle::update(sf::Time deltaTime) {
    // handle collisions with window bounds
    sf::Vector2f position = shape.getPosition();
    if (position.y < 0) {
        shape.setPosition(position.x, 0);
    }
    if (position.y + shape.getSize().y > 600) {
        shape.setPosition(position.x, 600 - shape.getSize().y);
    }
}

void Paddle::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void Paddle::moveUp() {
    //.016 modifier from examples and some tweeking with the speed
    shape.move(0, -speed * 0.016f);
}

void Paddle::moveDown() {
    shape.move(0, speed * 0.016f);
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}