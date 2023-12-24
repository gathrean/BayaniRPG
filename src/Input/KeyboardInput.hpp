//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Entities/Player.hpp"

class KeyboardInput {

public:

    static bool isKeyPressed(sf::Keyboard::Key key);

    static void handleMovement(Player& player, float movementSpeed);

};