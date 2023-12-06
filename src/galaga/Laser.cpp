//
// Created by sanpi on 12/6/2023.
//

#include "Laser.h"

Laser::Laser(float x, float y) {
    speed = 100.0f;
    shape.setSize(sf::Vector2f(5.f, 20.f));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Yellow);
}

void Laser::update(sf::Time deltaTime) {
    shape.move(0.f, -speed * deltaTime.asSeconds());
}

void Laser::render(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::FloatRect Laser::getBounds() const {
    return shape.getGlobalBounds();
}

bool Laser::checkCollision(const EnemyShip& enemyShip) const {
    sf::FloatRect laserBounds = shape.getGlobalBounds();
    sf::FloatRect enemyBounds = enemyShip.getBounds();

    return laserBounds.intersects(enemyBounds);
}