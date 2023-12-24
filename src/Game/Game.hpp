//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Window/Window.hpp"
#include "../Input/KeyboardInput.hpp"
#include "../Entities/Player.hpp"

class Game {
private:

    Window &mainWindow;
    Player player;

    float movementSpeed;

    sf::Clock enemySpawnTimer;

    float enemySpawnInterval;

public:

    Game()
            : mainWindow(Window::getInstance(1280, 960, "Dungeon Quad")),
              player(),
              movementSpeed(0.05f),
              enemySpawnInterval(5.0f) {

        player.setPlayerPosition(sf::Vector2f(100.f, 100.f));

        mainWindow.applyZoomOut(1.5f);

        mainWindow.spawnEnemy(20.0f, 0.025f, player.getPlayerPosition());
    }

    void run();

private:

    void handleEvents();

    void handleMouseClick();

    void updateGame();

    void renderGame();

};
