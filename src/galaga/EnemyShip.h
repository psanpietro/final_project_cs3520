//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_ENEMYSHIP_H
#define FINAL_PROJECT_CS3520_ENEMYSHIP_H

#include <SFML/Graphics.hpp>

class EnemyShip {
private:
    sf::CircleShape shape;
    sf::Texture texture;
    float speed;
public:
    //constructor just handles location inputs
    EnemyShip(float x, float y);
    //update values within the EnemyShip based on the change in time
    void update(sf::Time deltaTime);
    //render the ship in the given window
    void render(sf::RenderWindow& window) const;
    //provide the bounds of the ship for collision checking
    sf::FloatRect getBounds() const;
};


#endif //FINAL_PROJECT_CS3520_ENEMYSHIP_H
