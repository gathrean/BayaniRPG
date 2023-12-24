//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#include <SFML/Graphics.hpp>
#include "Window/Window.hpp"
#include "Input/KeyboardInput.hpp"
#include "Entities/Player.hpp"

int main() {

    unsigned int width = 1280;
    unsigned int height = 960;

    Window &mainWindow = Window::getInstance(width, height, "Dungeon Quad");
    Player player;
    player.setPlayerPosition(sf::Vector2f(100.f, 100.f));

    float movementSpeed = 0.1f;

    while (mainWindow.isWindowOpen()) {
        sf::Event event{};
        while (mainWindow.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mainWindow.closeWindow();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // If the left mouse button is pressed, shoot a projectile
                sf::Vector2i mousePos = sf::Mouse::getPosition(mainWindow.getWindow());
                sf::Vector2f worldPos = mainWindow.getWindow().mapPixelToCoords(mousePos);
                player.shootProjectiles(worldPos);
            }
        }

        KeyboardInput::handleMovement(player, movementSpeed);

        mainWindow.clearWindowContents();
        player.updateProjectiles(width, height);
        mainWindow.drawWindow(player);
        player.drawProjectiles(mainWindow.getWindow());
        mainWindow.displayWindow();
    }

    return 0;
}