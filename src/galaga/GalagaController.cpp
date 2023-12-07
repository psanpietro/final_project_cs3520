//
// Created by sanpi on 12/6/2023.
//

#include "GalagaController.h"

GalagaController::GalagaController(sf::RenderWindow& window)
        : window(window), laserHandler(), player(400.0f, 500.0f, laserHandler), enemies(), playerLasers(), enemyLasers() {
    spawnEnemies();
}

void GalagaController::handleInput() {
    player.handleInput();
}

void GalagaController::update(sf::Time deltaTime) {
    player.update(deltaTime);
    //this is a placeholder as the lasers in theory are handled by their ships.
    //or since this has access to the laserHandler given to the playerShip can handle it through there.
    for (auto& enemy : enemies) {
        enemy.update(deltaTime);
    }

    /*
    for (auto& enemyLaser : enemyLasers) {
        enemyLaser.update(deltaTime);
    }
    */
    //check if any ship has been hit and if more enemies need to be spawned.
    handleCollisions();
    cleanup();
    //spawnEnemies();
}

void GalagaController::render() {
    window.clear();

    //render all game objects as needed, again placeholder as lasers should be handled by their ships
    player.render(window);

    for (const auto& laser : playerLasers) {
        laser.render(window);
    }

    for (const auto& enemy : enemies) {
        enemy.render(window);
    }

    for (const auto& enemyLaser : enemyLasers) {
        enemyLaser.render(window);
    }

    window.display();
}

void GalagaController::spawnEnemies() {
    //start with 12 for testing
    const int numEnemies = 12;
    const float spacing = 60.f;

    for (int i = 0; i < numEnemies; ++i) {
        float x = i * spacing + 50.f;
        float y = 50.f;
        enemies.emplace_back(x, y);
    }
}

void GalagaController::handleCollisions() {
    //iterates through the enemyShips and marks any for removal if they collide with the player or their Lasers
    for (auto it = enemies.begin(); it != enemies.end();) {
        if (player.checkCollision(*it)) {
            enemies.erase(it);
            break;
        } else {
            ++it;
        }
    }
}

void GalagaController::cleanup() {

    /* no enemy lasers as of current moment
    enemyLasers.erase(
            std::remove_if(enemyLasers.begin(), enemyLasers.end(), [&](const Laser& Laser) {
                return Laser.getBounds().top > window.getSize().y;
            }),
            enemyLasers.end()
    );
     */
}