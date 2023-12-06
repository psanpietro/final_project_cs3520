//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_GALAGACONTROLLER_H
#define FINAL_PROJECT_CS3520_GALAGACONTROLLER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "Laser.h"

class GalagaController {
private:
    sf::RenderWindow& window;
    PlayerShip player;
    std::vector<EnemyShip> enemies;
    std::vector<Laser> playerLasers;
    std::vector<Laser> enemyLasers;

    void spawnEnemies();
    void handleCollisions();
    void cleanup();

    LaserHandler laserHandler;
public:
    explicit GalagaController(sf::RenderWindow& window);

    void handleInput();
    void update(sf::Time deltaTime);
    void render();


};

#endif //FINAL_PROJECT_CS3520_GALAGACONTROLLER_H
