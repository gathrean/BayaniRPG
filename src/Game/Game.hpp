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

    // Reference to the main window instance (Singleton)
    Window &mainWindow;

    // An instance of the player
    Player player;

    // Movement speed of the player
    float movementSpeed;

    // Timer for spawning enemies
    sf::Clock enemySpawnTimer;

    // Interval for spawning enemies
    float enemySpawnInterval;

public:

    /**
     * Constructor
     */
    Game()
            : mainWindow(Window::getInstance(1280, 960, "Dungeon Quad")),
              player(),
              movementSpeed(0.05f),
              enemySpawnInterval(5.0f) {

        // Initial player position
        player.setPlayerPosition(sf::Vector2f(100.f, 100.f));

        // Zoom out the View
        mainWindow.applyZoomOut(1.5f);

        // Start the game with one enemy
        mainWindow.spawnEnemy(20.0f, 0.025f, player.getPlayerPosition());
    }

    /**
     * Start the game loop
     * @pre The game is not running.
     * @post The game is running.
     */
    void run();

private:

    /**
     * Mouse click handler
     * @pre The mouse is clicked.
     * @post A projectile is shot from the player's position to the mouse's position.
     */
    void handleMouseClick();

    /**
     * Event handler
     * @pre The game is running.
     * @post Handles keyboard and mouse events.
     */
    void handleEvents();

    /**
     * Game updater
     * @pre The player is moving.
     * @pre The player is shooting projectiles.
     * @pre The enemies are moving.
     * @post The player and enemies are updated.
     */
    void updateGame();

    /**
     * Game renderer
     * @pre The window is cleared.
     * @post The window is drawn.
     * @post The player and projectiles are drawn.
     * @post The enemies are drawn.
     * @post The window is displayed.
     */
    void renderGame();

};
