//
// Created by sanpi on 12/6/2023.
//

#include "PongController.h"

PongController::PongController(sf::RenderWindow& window) : window(window), leftScore(0), rightScore(0) {
    if (!font.loadFromFile("Monocraft.ttf")) {
        std::cerr << "Error loading font\n";
    }

    ball = new Ball(window.getSize().x / 2.f, window.getSize().y / 2.f, 150.f);
    leftPaddle = new Paddle(30.f, window.getSize().y / 2.f);
    rightPaddle = new Paddle(window.getSize().x - 30.f, window.getSize().y / 2.f);

    // Setup score display
    leftScoreText.setFont(font);
    leftScoreText.setCharacterSize(30);
    leftScoreText.setPosition(50.f, 20.f);
    leftScoreText.setFillColor(sf::Color::Red);

    rightScoreText.setFont(font);
    rightScoreText.setCharacterSize(30);
    rightScoreText.setPosition(window.getSize().x - 80.f, 20.f);
    rightScoreText.setFillColor(sf::Color::Red);
}

void PongController::handleInput() {
    // Handle input for paddles
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        leftPaddle->moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        leftPaddle->moveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        rightPaddle->moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rightPaddle->moveDown();
    }
}

void PongController::update(sf::Time deltaTime) {
    ball->update(deltaTime);
    leftPaddle->update(deltaTime);
    rightPaddle->update(deltaTime);

    sf::FloatRect ballBounds = ball->getBounds();
    sf::FloatRect leftPaddleBounds = leftPaddle->getBounds();
    sf::FloatRect rightPaddleBounds = rightPaddle->getBounds();

    // collision with left paddle
    if (ballBounds.intersects(leftPaddleBounds)) {
        float ballCenterY = ballBounds.top + ballBounds.height / 2.f;
        float paddleCenterY = leftPaddleBounds.top + leftPaddleBounds.height / 2.f;
        float angle = (ballCenterY - paddleCenterY) / (leftPaddleBounds.height / 2.f);
        angle = std::min(1.f, std::max(-1.f, angle)); // limit the angle to [-1, 1]
        float speed = ball->getSpeed();
        ball->setVelocity(sf::Vector2f(speed * std::cos(angle), speed * std::sin(angle)));
    }

    // collision with right paddle
    if (ballBounds.intersects(rightPaddleBounds)) {
        float ballCenterY = ballBounds.top + ballBounds.height / 2.f;
        float paddleCenterY = rightPaddleBounds.top + rightPaddleBounds.height / 2.f;
        float angle = (ballCenterY - paddleCenterY) / (rightPaddleBounds.height / 2.f);
        angle = std::min(1.f, std::max(-1.f, angle));
        float speed = ball->getSpeed();
        float reflectionAngle = 3.14f - std::abs(angle);
        ball->setVelocity(sf::Vector2f(speed * std::cos(reflectionAngle), speed * std::sin(reflectionAngle)));
    }

    // Needed a margin because the out of bounds logic was only working sometimes with the ball
    float scoringMargin = 10.0f;
    if (ballBounds.left < scoringMargin) {
        // Ball went out on the left side, right player scores
        rightScore++;
        updateScores();
        ball->reset();
    } else if (ballBounds.left + ballBounds.width > window.getSize().x - scoringMargin) {
        // Ball went out on the right side, left player scores
        leftScore++;
        updateScores();
        ball->reset();
    }
}

void PongController::render() {
    // render game objects
    window.clear();
    ball->render(window);
    leftPaddle->render(window);
    rightPaddle->render(window);

    // draw scores
    window.draw(leftScoreText);
    window.draw(rightScoreText);

    window.display();
}

void PongController::updateScores() {
    leftScoreText.setString(std::to_string(leftScore));
    rightScoreText.setString(std::to_string(rightScore));
}