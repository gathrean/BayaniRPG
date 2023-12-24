//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Window.hpp"

Window::Window(unsigned int width, unsigned int height, const std::string &title)
        : window(sf::VideoMode(width, height), title, sf::Style::Resize) {

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
    for (float y = backgroundY; y < window.getSize().y; y += backgroundTexture.getSize().y) {
        for (float x = backgroundX; x < window.getSize().x; x += backgroundTexture.getSize().x) {
            backgroundSprite.setPosition(x, y);
            window.draw(backgroundSprite);
        }
    }
}

void Window::drawPlayerAndProjectiles(Player &player) {
    player.drawPlayer(window);
    player.drawProjectiles(window);
    player.updateProjectiles(window.getSize().x, window.getSize().y);
}