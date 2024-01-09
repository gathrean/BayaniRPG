//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Entity.hpp"

class Projectile : public Entity {

private:
    
    // The shape of the projectile
    sf::CircleShape projectile;
    
    // The velocity of the projectile
    sf::Vector2f velocity;
    
    // The radius of the projectile
    float projectileRadius = 5.0f;

public:
    
    // Constructor
    Projectile();
    
    // Update the projectile
    void updateProjectile();
    
    // Draw the projectile
    // Overrides the Entity's draw method
    void draw(sf::RenderWindow& window) override;
    
    // Get the position of the projectile
    // Overrides the Entity's getPosition method
    sf::Vector2f getPosition() const override;
    
    // Set the position of the projectile
    void setPosition(sf::Vector2f position);
    
    // Set the velocity of the projectile
    void setVelocity(sf::Vector2f vel);
};
