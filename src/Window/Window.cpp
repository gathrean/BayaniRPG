//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Window.hpp"

void Window::drawWindow(Player player) {
    window.clear();

    // Update background position based on player direction
    backgroundX -= player.getDirection().x;
    backgroundY -= player.getDirection().y;

    // Tile the background image
    int offsetX = static_cast<int>(std::fmod(backgroundX, backgroundTexture.getSize().x));
    int offsetY = static_cast<int>(std::fmod(backgroundY, backgroundTexture.getSize().y));

    // Draw the tiled background image in both directions for a seamless effect
    for (int x = offsetX; x < window.getSize().x; x += backgroundTexture.getSize().x) {
        for (int y = offsetY; y < window.getSize().y; y += backgroundTexture.getSize().y) {
            backgroundSprite.setPosition(x, y);
            window.draw(backgroundSprite);
        }
    }

    // Draw the player on top of the background
    player.drawPlayer(window);
}
