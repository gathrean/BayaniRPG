//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#pragma once

#include <SFML/Graphics.hpp>

/**
 * Entity is an abstract class that represents an object in the game.
 */
class Entity {
public:

    // Draws the entity to the window.
    virtual void draw(sf::RenderWindow& window) = 0;

    // Updates the entity.
    virtual sf::Vector2f getPosition() const = 0;

    // Destructor for the entity.
    virtual ~Entity() = default;
};

