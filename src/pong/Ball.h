//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_BALL_H
#define FINAL_PROJECT_CS3520_BALL_H

#include "GameObject.h"

class Ball : public GameObject {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float speed;
public:
    Ball(float startX, float startY, float initialSpeed);

    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;

    void reset();
    sf::FloatRect getBounds() const;
    float getSpeed() const;
    void setVelocity(const sf::Vector2f& newVelocity);


};



#endif //FINAL_PROJECT_CS3520_BALL_H
