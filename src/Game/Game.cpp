//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#include "Game.hpp"

void Game::run() {
    while (mainWindow.isWindowOpen()) {
        handleEvents();
        updateGame();
        renderGame();
    }
}

void Game::handleMouseClick() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(mainWindow.getWindow());
    sf::Vector2f worldPos = mainWindow.getWindow().mapPixelToCoords(mousePos);
    player.shootProjectiles(worldPos);
}

void Game::handleEvents() {
    sf::Event event{};
    while (mainWindow.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mainWindow.closeWindow();
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            handleMouseClick();
        }
    }
    KeyboardInput::handleMovement(player, movementSpeed);
}

void Game::updateGame() {
    mainWindow.updateEnemies(player);

    if (enemySpawnTimer.getElapsedTime().asSeconds() >= enemySpawnInterval) {
        mainWindow.spawnEnemy(20.0f, 0.025f, player.getPlayerPosition());
        enemySpawnTimer.restart();
    }

    player.updateProjectiles(mainWindow.getView());
}

void Game::renderGame() {
    mainWindow.clearWindowContents();
    mainWindow.drawWindow(player);
    player.drawProjectiles(mainWindow.getWindow());
    mainWindow.drawEnemies();
    mainWindow.displayWindow();
}