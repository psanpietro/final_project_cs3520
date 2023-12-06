//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_PADDLE_H
#define FINAL_PROJECT_CS3520_PADDLE_H

#include "GameObject.h"

class Paddle : public GameObject {
private:
    sf::RectangleShape shape;
    float speed;
public:
    Paddle(float startX, float startY);

    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;

    void moveUp();
    void moveDown();
    sf::FloatRect getBounds() const;


};

#endif //FINAL_PROJECT_CS3520_PADDLE_H
