//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_PLAYERSHIP_H
#define FINAL_PROJECT_CS3520_PLAYERSHIP_H

#include <SFML/Graphics.hpp>
#include "LaserHandler.h"

class PlayerShip {
private:
    sf::RectangleShape shape;
    float speed;
    // a LaserHandler handles all of the Ship's lasers and their movement and eventually their collision.
    LaserHandler& laserHandler;
    // indicate whether a new laser has been created
    bool newLaserCreated;
    //this value is used to prevent a laser from being created unless 60 frames have been rendered
    int timeUntilNewLaser;
public:
    PlayerShip(float x, float y, LaserHandler& laserHandler);

    void handleInput();
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);

    //attempt to limit the creation of a laser to one at a time.
    void limitLaserCreation();

    //takes in an EnemyShip and returns true if it collided with itself or a laser
    bool checkCollision(const EnemyShip& enemy);

};

#endif //FINAL_PROJECT_CS3520_PLAYERSHIP_H
