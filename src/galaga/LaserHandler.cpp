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
}

void LaserHandler::render(sf::RenderWindow& window) {
    for (const auto& laser : lasers) {
        laser->render(window);
    }
}



