//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_LASER_H
#define FINAL_PROJECT_CS3520_LASER_H


#include <SFML/Graphics.hpp>
#include "EnemyShip.h"

class Laser {
private:
    sf::RectangleShape shape;
    float speed;
    bool playerBullet;
public:
    Laser(float x, float y);

    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    bool checkCollision(const EnemyShip& enemyShip) const;
};


#endif //FINAL_PROJECT_CS3520_LASER_H
