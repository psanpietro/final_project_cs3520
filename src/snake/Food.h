//
// Created by sanpi on 12/7/2023.
//

#ifndef FINAL_PROJECT_CS3520_FOOD_H
#define FINAL_PROJECT_CS3520_FOOD_H


#include <SFML/Graphics.hpp>

class Food {
private:
    sf::Vector2f position;
    sf::Vector2u windowSize;
public:
    explicit Food(const sf::Vector2u& windowSize);
    void respawn();
    [[nodiscard]] const sf::Vector2<float> getPosition() const;
};




#endif //FINAL_PROJECT_CS3520_FOOD_H
