//
// Created by sanpi on 12/6/2023.
//

#include "GameSelector.h"

/*
 * This class was an attempt at creating an initial window to select all available games, however it caused
 * graphical glitches that I was unable to fix quickly so I moved to a command line version of launching.
 */

GameSelector::GameSelector(sf::RenderWindow& window) : window(&window), selectedGame(GameSelection::None) {
    ImGui::SFML::Init(window);
}

GameSelector::~GameSelector() {
    ImGui::SFML::Shutdown();
}

void GameSelector::handleInput() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        ImGui::SFML::ProcessEvent(event);
    }
}

void GameSelector::update() {
    ImGui::SFML::Update(*window, frameClock.restart());
}

void GameSelector::render() {
    window->clear();
    ImGui::SFML::Render(*window);
}

void GameSelector::display() {
    window->display();
}

GameSelection GameSelector::getSelectedGame() const {
    return selectedGame;
}

void GameSelector::launchSelectedGame() {
    if (selectedGame == GameSelection::Galaga) {
        GalagaController galagaController(*window);
        while (window->isOpen() && selectedGame == GameSelection::Galaga) {
            handleInput();
            update();
            render();
            galagaController.handleInput();
            galagaController.update(sf::seconds(1.0f / 60.0f));
            galagaController.render();
            display();
        }
    } else if (selectedGame == GameSelection::Pong) {
        PongController pongController(*window);
        while (window->isOpen() && selectedGame == GameSelection::Pong) {
            handleInput();
            update();
            render();
            pongController.handleInput();
            pongController.update(sf::seconds(1.0f / 60.0f));
            pongController.render();
            display();
        }
    }

    // reset the selected game after it is closed
    selectedGame = GameSelection::None;
}