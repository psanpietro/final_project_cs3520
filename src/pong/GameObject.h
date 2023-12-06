//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_GAMEOBJECT_H
#define FINAL_PROJECT_CS3520_GAMEOBJECT_H

#include "SFML/Graphics.hpp"

class GameObject {
public:
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif //FINAL_PROJECT_CS3520_GAMEOBJECT_H
