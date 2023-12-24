//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Window.hpp"

void Window::drawCheckeredBackground() {
    constexpr int tileSize = 50; // Size of each tile
    sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));

    bool isWhite = true;
    for (int y = 0; y < window.getSize().y; y += tileSize) {
        isWhite = !isWhite; // Alternate the pattern
        for (int x = 0; x < window.getSize().x; x += tileSize) {
            tile.setPosition(static_cast<float>(x), static_cast<float>(y));
            tile.setFillColor(isWhite ? sf::Color::Blue : sf::Color::Black);
            window.draw(tile);
            isWhite = !isWhite; // Switch color for the next tile
        }
    }
}

void Window::drawWindow(Player player) {
    drawCheckeredBackground(); // Draw the checkered background
    player.drawPlayer(window); // Draw the player
}