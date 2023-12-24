//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Window.hpp"

Window::Window(unsigned int width, unsigned int height, const std::string &title)
        : window(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close) {

    bool isBackgroundLoaded = backgroundTexture.loadFromFile(backgroundFileName);

    if (isBackgroundLoaded) {
        backgroundSprite.setTexture(backgroundTexture); // Set the texture for the sprite
    } else {
        // Handle error when loading the background texture
        std::cout << "Failed to load background texture!" << std::endl;
    }

    // Set an initial view for the window
    view.setSize(static_cast<float>(width), static_cast<float>(height));
    view.setCenter(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
    window.setView(view);
}

void Window::drawWindow(Player player) {
    window.clear();

    updateBackgroundPosition(player);
    drawTiledBackground();

    // Center the view on the player's position
    view.setCenter(player.getPlayerPosition());
    window.setView(view);

    drawPlayerAndProjectiles(player);
}

void Window::updateBackgroundPosition(const Player &player) {
    sf::Vector2f playerPosition = player.getPlayerPosition();

    float offsetX = std::fmod(playerPosition.x, static_cast<float>(backgroundTexture.getSize().x));
    float offsetY = std::fmod(playerPosition.y, static_cast<float>(backgroundTexture.getSize().y));

    // Update backgroundX and backgroundY based on player's position
    backgroundX = -offsetX;
    backgroundY = -offsetY;
}

void Window::drawTiledBackground() {
    sf::Vector2u textureSize = backgroundTexture.getSize();

    // Calculate the number of tiles needed to cover an extended area
    int tilesX = static_cast<int>(std::ceil(window.getSize().x / static_cast<float>(textureSize.x)));
    int tilesY = static_cast<int>(std::ceil(window.getSize().y / static_cast<float>(textureSize.y)));

    // Extend the rendering area in both directions
    int extendX = 12; // Adjust this value to increase the number of tiles rendered horizontally
    int extendY = 8; // Adjust this value to increase the number of tiles rendered vertically

    // Calculate the starting point for rendering the tiles
    float startX = backgroundX - extendX * textureSize.x;
    float startY = backgroundY - extendY * textureSize.y;

    for (int y = 0; y < tilesY + extendY * 2; ++y) {
        for (int x = 0; x < tilesX + extendX * 2; ++x) {
            float xPos = startX + x * textureSize.x;
            float yPos = startY + y * textureSize.y;

            backgroundSprite.setPosition(xPos, yPos);
            window.draw(backgroundSprite);
        }
    }
}

void Window::drawPlayerAndProjectiles(Player &player) {
    player.drawPlayer(window);
    player.drawProjectiles(window);
    player.updateProjectiles(view);
}

void Window::spawnEnemy(float radius, float moveSpeed, const sf::Vector2f& playerPosition) {
    enemies.emplace_back(radius, moveSpeed, playerPosition);
}


void Window::drawEnemies() {
    for (auto &enemy: enemies) {
        enemy.drawEnemy(window);
    }
}

void Window::updateEnemies(Player &player) {
    sf::Vector2f playerPos = player.getPlayerPosition();
    for (auto &enemy: enemies) {
        enemy.updatePosition(playerPos);
    }
}