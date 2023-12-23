//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "KeyboardInput.hpp"
#include "Player.hpp"

int main() {
    Window& mainWindow = Window::getInstance(1280, 960, "Dungeon Quad");
    Player player;
    player.setPosition(sf::Vector2f(100.f, 100.f));

    float movementSpeed = 0.1f;

    while (mainWindow.isOpen()) {
        sf::Event event{};
        while (mainWindow.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mainWindow.close();
        }

        KeyboardInput::handleMovement(player, movementSpeed);

        mainWindow.clear();
        mainWindow.draw(player);
        mainWindow.display();
    }

    return 0;
}