//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Window/Window.hpp"
#include "../Input/KeyboardInput.hpp"
#include "../Entities/Player/Player.hpp"
#include "GameConstants.hpp"

/**
 * Game class
 */
class Game {
private:
    
    // Reference to the main window instance (Singleton)
    Window& mainWindow;
    
    // An instance of the player
    Player player;
    
    // Movement speed of the player
    float movementSpeed;
    
    // Timer for spawning enemies
    sf::Clock enemySpawnTimer;
    
    // Interval for spawning enemies
    float enemySpawnInterval;

public:
    
    // Constructor
    Game() : mainWindow(Window::getInstance(GameConstants::WINDOW_WIDTH, GameConstants::WINDOW_HEIGHT, GameConstants::WINDOW_TITLE)),
             player(),
             movementSpeed(GameConstants::PLAYER_MOVEMENT_SPEED),
             enemySpawnInterval(GameConstants::ENEMY_SPAWN_INTERVAL) {
        
        // Initial player position
        player.setPlayerPosition(sf::Vector2f(100.f, 100.f));
        
        // Zoom out the View
        mainWindow.applyZoomOut(1.5f);
        
        // Start the game with enemies
        mainWindow.spawnEnemy(20.0f, 0.025f, player.getPosition());
    }
    
    // Start game loop
    void run();

private:
    
    // Handle mouse clicks
    void handleMouseClick();
    
    // Handle events
    // Such as mouse clicks, key presses, etc.
    void handleEvents();
    
    // Update the game
    void updateGame();
    
    // Render the game
    void renderGame();
    
};
