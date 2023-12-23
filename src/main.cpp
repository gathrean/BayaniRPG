//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "KeyboardInput.hpp"

int main() {
    Window& mainWindow = Window::getInstance(1280, 960, "Dungeon Quad");
    sf::CircleShape shape;
    shape.setRadius(20.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);

    float movementSpeed = 0.1f; // Adjust the movement speed

    while (mainWindow.isOpen()) {
        sf::Event event{};

        while (mainWindow.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mainWindow.close();
        }

        KeyboardInput::handleMovement(shape, movementSpeed);

        mainWindow.clear();
        mainWindow.draw(shape);
        mainWindow.display();
    }

    return 0;
}