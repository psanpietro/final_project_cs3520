//
// Created by sanpi on 12/6/2023.
//

#include "EnemyShip.h"

EnemyShip::EnemyShip(float x, float y) {
    shape.setRadius(20.f);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Red);
}

void EnemyShip::update(sf::Time deltaTime) {
   //stub to determine how to update and cause movement later
}

void EnemyShip::render(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::FloatRect EnemyShip::getBounds() const {
    return shape.getLocalBounds();
}
