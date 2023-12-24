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

    /**
     * Draws the entity to the window.
     * @param window - A reference to the window to draw to.
     */
    virtual void draw(sf::RenderWindow& window) = 0;

    /**
     * Gets the position of the entity.
     * @return - The position of the entity using SFML's Vector2f.
     */
    virtual sf::Vector2f getPosition() const = 0;

    /**
     * Virtual destructor for the Entity class.
     */
    virtual ~Entity() = default;
};

