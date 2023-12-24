//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Entities/Player/Player.hpp"
#include "../Entities/Enemy/Enemy.hpp"

class Window {

private:
    sf::RenderWindow window;        // Add a window to render the game
    sf::Texture backgroundTexture;  // Add a texture for the background
    sf::Sprite backgroundSprite;    // Add a sprite to render the background texture
    sf::View view;                  // Add a view to the window (for zooming out)
    sf::Clock enemySpawnTimer;      // Timer for enemy spawn

    float enemySpawnInterval = 5.0f; // Interval between enemy spawns (in seconds)

    std::vector<Enemy> enemies;     // Vector to store enemies

    std::string backgroundFileName = "../media/deep_slate.jpg";

    // Background's positions
    float backgroundX = 0.0f;
    float backgroundY = 0.0f;

    // Singleton
    Window(unsigned int width, unsigned int height, const std::string& title);

public:
    // Singleton instance getter
    static Window& getInstance(unsigned int width, unsigned int height, const std::string& title) {
        static Window instance(width, height, title);
        return instance;
    }

    inline sf::View getView() {
        return view;
    }

    // Handles the logic of drawing the window.
    // Calls the functions to draw the background, player, and projectiles.
    void drawWindow(Player player);

    // Update the background position based on the player's position
    // This function is called by drawWindow()
    void updateBackgroundPosition(const Player& player);

    // Draw the tiled background
    // This function is called by drawWindow()
    void drawTiledBackground();

    // Draw the player and projectiles
    // This function is called by drawWindow()
    void drawPlayerAndProjectiles(Player& player);

    // Method to spawn enemies
    void spawnEnemy(float radius, float moveSpeed, const sf::Vector2f& playerPosition);

    // Method to draw all enemies
    void drawEnemies();

    // Method to update enemy positions based on the player's position
    void updateEnemies(Player& player);

    // Method to spawn enemies at intervals
    void spawnEnemiesAtIntervals();

    // Display the window
    inline void displayWindow() {
        window.display();
    }

    // Clear the window
    inline void clearWindowContents() {
        window.clear();
    }

    // Close the window
    inline void closeWindow() {
        window.close();
    }

    // Check if the window is open
    inline bool isWindowOpen() const {
        return window.isOpen();
    }

    // Getter for the window
    inline sf::RenderWindow& getWindow() {
        return window;
    }

    // Singleton: deleted copy constructor
    Window(const Window&) = delete;

    // Singleton: deleted assignment operator
    Window& operator=(const Window&) = delete;

    // Add a method to apply the zoom-out effect
    void applyZoomOut(float factor) {
        sf::Vector2f newSize = view.getSize() * factor;
        view.setSize(newSize);
        window.setView(view);
    }

    // Destructor
    ~Window() { window.close(); }
};