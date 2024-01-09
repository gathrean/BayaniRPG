//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Entity.hpp"
#include "../HealthBar/HealthBar.hpp"

class Enemy : public Entity {

private:
    
    // Enemy shape / Hit box
    sf::CircleShape shape;

    // Direction for enemy to follow
    sf::Vector2f direction;

    // Enemy speed
    float speed;

protected:
    
    // Enemy health
    HealthBar healthBar;

public:
    
    // Constructor
    Enemy(float radius, float moveSpeed, const sf::Vector2f& playerPosition);

    // Draw the enemy
    // Overrides the Entity's draw method
    void draw(sf::RenderWindow& window) override;

    // Get the position of the enemy
    // Overrides the Entity's getPosition method
    sf::Vector2f getPosition() const override;
    
    // Update where the enemy is
    void updatePosition(const sf::Vector2f& playerPosition);

    // Calculate the magnitude of a vector
    float magnitude(const sf::Vector2f& vector);
    
    // Normalize a vector
    void normalize(sf::Vector2f& vector);
    
    // Set maximum health for the enemy
    void setMaxHealth(float maxHealth);
    
    // Set current health for the enemy
    void setCurrentHealth(float currentHealth);
};
