//
// Created by sanpi on 12/6/2023.
//

#include "PlayerShip.h"


PlayerShip::PlayerShip(float x, float y, LaserHandler& laserHandler1)
        : speed(200.f), laserHandler(laserHandler1) {
    shape.setSize(sf::Vector2f(30.f, 50.f));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Green);
    timeUntilNewLaser = 0;
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
    ++timeUntilNewLaser;
    if (timeUntilNewLaser >= 60){
        newLaserCreated = false;
        timeUntilNewLaser = 0;
    }

}

void PlayerShip::limitLaserCreation()  {
    newLaserCreated = true;
}

bool PlayerShip::checkCollision(const EnemyShip& enemy) {
    //first check collision against this PlayerShip
    sf::FloatRect playerBounds = shape.getGlobalBounds();
    sf::FloatRect enemyBounds = enemy.getBounds();

    if (playerBounds.intersects(enemyBounds)) {
        return true;
    }
    //second ask the laserHandler if any laser has hit that enemy ship
    return laserHandler.checkCollision(enemy);

}
