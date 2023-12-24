//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Window.hpp"

void Window::drawWindow(Player player) {
    window.clear();

    // Update background position based on player direction
    backgroundX -= player.getDirection().x;
    backgroundY -= player.getDirection().y;

    unsigned int textureWidth = backgroundTexture.getSize().x;
    unsigned int textureHeight = backgroundTexture.getSize().y;

    // Tile the background image
    int offsetX = static_cast<int>(std::fmod(backgroundX, textureWidth));
    int offsetY = static_cast<int>(std::fmod(backgroundY, textureHeight));

    unsigned int windowWidth = window.getSize().x;
    unsigned int windowHeight = window.getSize().y;

    // Draw the tiled background image in both directions for a seamless effect
    for (unsigned int x = offsetX; x < windowWidth; x += textureWidth) {
        for (unsigned int y = offsetY; y < windowHeight; y += textureHeight) {
            backgroundSprite.setPosition(x, y);
            window.draw(backgroundSprite);
        }
    }

    // Draw the player on top of the background
    player.drawPlayer(window);
}
