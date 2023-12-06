//
// Created by sanpi on 12/6/2023.
//

#ifndef FINAL_PROJECT_CS3520_GAMESELECTOR_H
#define FINAL_PROJECT_CS3520_GAMESELECTOR_H

#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/System/Clock.hpp>

#include "../galaga/GalagaController.h"
#include "../pong/PongController.h"

enum class GameSelection {
    None,
    Galaga,
    Pong
};

class GameSelector {
private:
    sf::RenderWindow* window;
    GameSelection selectedGame;
    sf::Clock frameClock;

public:
    GameSelector(sf::RenderWindow& window);
    ~GameSelector();

    void handleInput();
    void update();
    void render();
    void display();

    GameSelection getSelectedGame() const;
    void launchSelectedGame();

};

#endif //FINAL_PROJECT_CS3520_GAMESELECTOR_H
