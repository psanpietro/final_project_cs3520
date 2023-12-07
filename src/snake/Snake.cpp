//
// Created by sanpi on 12/7/2023.
//

#include "Snake.h"

Snake::Snake(const sf::Vector2u& windowSize, float initialSpeed)
        : windowSize(windowSize), speed(initialSpeed), direction(Direction::Right) {
    position = sf::Vector2f(20.0f, 20.0f);
    blockSize = 20.0f;
    body.push_back(position);
}

void Snake::update(sf::Time deltaTime) {
    move(deltaTime);

    if (checkCollision()) {
        reset();
    }
}

void Snake::setDirection(Snake::Direction newDirection) {
    //makes sure direction cannot be set to be its opposite.
    if ((newDirection == Direction::Up && direction != Direction::Down) ||
        (newDirection == Direction::Down && direction != Direction::Up) ||
        (newDirection == Direction::Left && direction != Direction::Right) ||
        (newDirection == Direction::Right && direction != Direction::Left)) {
        direction = newDirection;
    }
}

const std::vector<sf::Vector2f>& Snake::getBody() const {
    return body;
}

void Snake::move(sf::Time deltaTime) {
    // change speed based on the current direction
    float delta = speed * deltaTime.asSeconds();
    sf::Vector2f movement(0.f, 0.f);

    switch (direction) {
        case Direction::Up:
            movement.y -= delta;
            break;
        case Direction::Down:
            movement.y += delta;
            break;
        case Direction::Left:
            movement.x -= delta;
            break;
        case Direction::Right:
            movement.x += delta;
            break;
    }

    // make sure the snake stays within the window bounds
    if (position.x < 0) position.x = windowSize.x - 1;
    if (position.x >= windowSize.x) position.x = 0;
    if (position.y < 0) position.y = windowSize.y - 1;
    if (position.y >= windowSize.y) position.y = 0;
}

bool Snake::checkCollision() const {
    sf::Vector2f headPos = body.front();

    // check for collision with walls
    if (headPos.x < 0 || headPos.y < 0 || headPos.x >= windowSize.x || headPos.y >= windowSize.y) {
        return true;
    }
    // check for collision with itself
    //i don't trust that this works
    for (size_t i = 1; i < body.size(); ++i) {
        if (headPos == body[i]) {
            return true;
        }
    }

    return false;
}

void Snake::reset() {
    position = sf::Vector2f(blockSize, blockSize);
    direction = Direction::Right;
    body.clear();
    body.push_back(position);
}

void Snake::grow() {
    //very much not confident this add correctly to the render at least
    sf::Vector2f newSegmentPos;
    switch (direction) {
        case Direction::Up:
            newSegmentPos = body.front() + sf::Vector2f(0, -blockSize);
            break;
        case Direction::Down:
            newSegmentPos = body.front() + sf::Vector2f(0, blockSize);
            break;
        case Direction::Left:
            newSegmentPos = body.front() + sf::Vector2f(-blockSize, 0);
            break;
        case Direction::Right:
            newSegmentPos = body.front() + sf::Vector2f(blockSize, 0);
            break;
    }
    body.push_back(newSegmentPos);
}

Snake::Direction Snake::getDirection() {
    return direction;
}

void Snake::render(sf::RenderWindow& window) const {
    for (const auto& segment : body) {
        sf::RectangleShape rect = sf::RectangleShape(segment);
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
    }
}
