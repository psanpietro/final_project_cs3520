//
// Created by sanpi on 12/7/2023.
//

#include "Food.h"
#include <cstdlib>

Food::Food(const sf::Vector2u& windowSize) : windowSize(windowSize) {
    respawn();
}

void Food::respawn() {
    //update food object with new position randomly
    position.x = rand() % windowSize.x;
    position.y = rand() % windowSize.y;
}

const sf::Vector2<float> Food::getPosition() const {
    return position;
}