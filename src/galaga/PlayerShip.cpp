//
// Created by sanpi on 12/6/2023.
//

#include "PlayerShip.h"


PlayerShip::PlayerShip(float x, float y, LaserHandler& laserHandler1)
        : speed(200.f), laserHandler(laserHandler1) {
    shape.setSize(sf::Vector2f(50.f, 30.f));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Green);
}

void PlayerShip::handleInput() {
    //stub most of the input handling is in the update
}

void PlayerShip::update(sf::Time deltaTime) {
    // handle input for shooting
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !newLaserCreated) {
        laserHandler.createLaser(shape.getPosition().x + shape.getSize().x / 2,
                                 shape.getPosition().y);
        limitLaserCreation();
    }
    // handle movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && shape.getPosition().x > 0) {
        shape.move(-speed * deltaTime.asSeconds(), 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        shape.getPosition().x + shape.getSize().x < 800) {
        shape.move(speed * deltaTime.asSeconds(), 0.f);
    }
    laserHandler.update(deltaTime);

}

void PlayerShip::render(sf::RenderWindow& window) {
    window.draw(shape);
    laserHandler.render(window);
}

void PlayerShip::limitLaserCreation()  {
    newLaserCreated = true;
}
