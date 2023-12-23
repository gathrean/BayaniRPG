//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#include "KeyboardInput.hpp"

bool KeyboardInput::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

void KeyboardInput::handleMovement(sf::CircleShape& shape, float movementSpeed) {
    if (isKeyPressed(sf::Keyboard::A)) {
        shape.move(-movementSpeed, 0);
    }
    if (isKeyPressed(sf::Keyboard::D)) {
        shape.move(movementSpeed, 0);
    }
    if (isKeyPressed(sf::Keyboard::W)) {
        shape.move(0, -movementSpeed);
    }
    if (isKeyPressed(sf::Keyboard::S)) {
        shape.move(0, movementSpeed);
    }
}
