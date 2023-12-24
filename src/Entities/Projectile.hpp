//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Projectile : public Entity {
private:
    sf::CircleShape projectile;

    sf::Vector2f velocity;

    float projectileRadius = 5.0f;

public:

    // Constructor
    Projectile();

    // Methods

    void updateProjectile();

    void draw(sf::RenderWindow& window) override;

    // Getters and Setters

    sf::Vector2f getPosition() const override;

    void setPosition(sf::Vector2f position);

    void setVelocity(sf::Vector2f vel);

};
