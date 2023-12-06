//
// Created by sanpi on 12/6/2023.
//

#include "Ball.h"

Ball::Ball(float startX, float startY, float initialSpeed) : speed(initialSpeed) {
    shape.setRadius(10.f);
    shape.setPosition(startX, startY);
    shape.setFillColor(sf::Color::White);
    velocity = sf::Vector2f(initialSpeed, initialSpeed);
}

void Ball::update(sf::Time deltaTime) {
    // update ball position based on velocity
    shape.move(velocity * deltaTime.asSeconds());

    sf::Vector2f position = shape.getPosition();
    if (position.x < 0 || position.x + 2 * shape.getRadius() > 800) {
        velocity.x = -velocity.x; // flip x direction on window bounds
    }
    if (position.y < 0 || position.y + 2 * shape.getRadius() > 600) {
        velocity.y = -velocity.y; // flip y direction on window bounds
    }

    // reset ball if out of bounds
    if (position.x < 0 || position.x + 2 * shape.getRadius() > 800) {
        reset();
    }
}

void Ball::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void Ball::reset() {
    // reset ball position to the center of the original window size from main
    shape.setPosition(400.f, 300.f);
}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}

float Ball::getSpeed() const {
    return speed;
}

void Ball::setVelocity(const sf::Vector2f& newVelocity) {
    velocity = newVelocity;
}