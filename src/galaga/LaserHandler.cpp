//
// Created by sanpi on 12/6/2023.
//

#include "LaserHandler.h"

void LaserHandler::createLaser(float x, float y) {
    lasers.push_back(std::make_unique<Laser>(x, y));
}

void LaserHandler::update(sf::Time deltaTime) {
    for (auto& laser : lasers) {
        laser->update(deltaTime);
    }
    //removes any laser that is out of Bounds of the window.
    lasers.erase(
            std::remove_if(lasers.begin(), lasers.end(), [&](const std::unique_ptr<Laser>& laser) {
                return laser->getBounds().top + laser->getBounds().height < 0;
            }),
            lasers.end()
    );

}

void LaserHandler::render(sf::RenderWindow& window) {
    for (const auto& laser : lasers) {
        laser->render(window);
    }
}

bool LaserHandler::checkCollision(const EnemyShip& enemy) {
    //check if the bounds of the lasers that this class handles are in collision with the bounds of the enemy
    //delete that laser from this class and the board and return true.
    for (auto it = lasers.begin(); it != lasers.end();) {
        if ((*it)->checkCollision(enemy)) {
            lasers.erase(it);
            return true;
        } else {
            ++it;
        }
    }
    return false;
}



