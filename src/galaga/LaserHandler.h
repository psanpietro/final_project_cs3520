//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_LASERHANDLER_H
#define FINAL_PROJECT_CS3520_LASERHANDLER_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "Laser.h"

class LaserHandler {
private:
    std::vector<std::unique_ptr<Laser>> lasers;
public:
    void createLaser(float x, float y);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);

};


#endif //FINAL_PROJECT_CS3520_LASERHANDLER_H
