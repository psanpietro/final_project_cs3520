//
// Created by sanpi on 12/7/2023.
//

#ifndef FINAL_PROJECT_CS3520_SNAKE_H
#define FINAL_PROJECT_CS3520_SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
public:
    enum class Direction {
        Up,
        Down,
        Left,
        Right
    };

    Snake(const sf::Vector2u& windowSize, float initialSpeed);
    void update(sf::Time deltaTime);
    void setDirection(Direction newDirection);
    [[nodiscard]] const std::vector<sf::Vector2f>& getBody() const;
    [[nodiscard]] bool checkCollision() const;
    void reset();
    void grow();
    void render(sf::RenderWindow& window) const;
    Direction getDirection();
private:
    sf::Vector2f position;
    sf::Vector2u windowSize;
    float speed;
    //needs to be declared after enum is declared
    Direction direction;
    std::vector<sf::Vector2f> body;
    float blockSize;

    void move(sf::Time deltaTime);

};

#endif //FINAL_PROJECT_CS3520_SNAKE_H
