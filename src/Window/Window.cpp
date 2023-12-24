//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Window.hpp"

void Window::drawWindow(Player player) {
    window.clear();

    // Update background position based on player position
    sf::Vector2f playerPosition = player.getPlayerPosition();

    // Calculate the offset for tiling the background
    float offsetX = std::fmod(playerPosition.x, static_cast<float>(backgroundTexture.getSize().x));
    float offsetY = std::fmod(playerPosition.y, static_cast<float>(backgroundTexture.getSize().y));

    // Draw the tiled background
    for (float y = -offsetY; y < window.getSize().y; y += backgroundTexture.getSize().y) {
        for (float x = -offsetX; x < window.getSize().x; x += backgroundTexture.getSize().x) {
            backgroundSprite.setPosition(x, y);
            window.draw(backgroundSprite);
        }
    }

    // Draw the player on top of the background
    player.drawPlayer(window);
    player.drawProjectiles(window);

    // Update and draw projectiles
    player.updateProjectiles(window.getSize().x, window.getSize().y);
}