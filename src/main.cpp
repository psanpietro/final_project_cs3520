#include <SFML/Graphics.hpp>
#include "imgui-SFML.h"
#include "pong/PongController.h"
#include "galaga/GalagaController.h"
#include "snake/SnakeController.h"  // Include SnakeController

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "please input a game as one more argument ";
        return 1;
    }

    std::string game = argv[1];

    if (game == "pong") {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
        PongController pongController(window);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            pongController.handleInput();
            pongController.update(sf::seconds(1.0f / 60.0f));
            pongController.render();
        }
    } else if (game == "galaga") {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Galaga");
        GalagaController galagaController(window);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            galagaController.handleInput();
            galagaController.update(sf::seconds(1.0f / 60.0f));
            galagaController.render();
        }
    } else if (game == "snake") {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
        SnakeController snakeController(window);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            snakeController.handleInput();
            snakeController.update(sf::seconds(1.0f / 60.0f));
            snakeController.render();
        }
    } else if (game == "-t") {
        std::cout << "compiled successfully" << std::endl;
        return 0;
    } else {
        std::cerr << "Unknown game: " << game << "\n";
        return 1;
    }

    return 0;
}
