//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#include "KeyboardInput.hpp"

bool KeyboardInput::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

void KeyboardInput::handleMovement(Player& player, float movementSpeed) {
    if (isKeyPressed(sf::Keyboard::A)) {
        player.move(-movementSpeed, 0);
    }
    if (isKeyPressed(sf::Keyboard::D)) {
        player.move(movementSpeed, 0);
    }
    if (isKeyPressed(sf::Keyboard::W)) {
        player.move(0, -movementSpeed);
    }
    if (isKeyPressed(sf::Keyboard::S)) {
        player.move(0, movementSpeed);
    }
}
