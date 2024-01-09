//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Projectile/Projectile.hpp"
#include "../Entity.hpp"
#include "../HealthBar/HealthBar.hpp"

class Player : public Entity {

private:

    // The player's radius (used for collision detection)
    float playerRadius = 50.f;

    // The player's shape / hit box
    sf::CircleShape shape;

    // The player's projectiles vector
    std::vector<Projectile> playerProjectiles;

    // The player's direction
    sf::Vector2f direction;

protected:
    // The player's health
    HealthBar healthBar;

public:
    
    // Constructor
    Player();

    // Destructor
    ~Player() override = default;
    
    // Draw the player
    // Overrides the Entity's draw method
    void draw(sf::RenderWindow& window) override;
    
    // Draw the player's health bar
    void drawHealthBar(sf::RenderWindow& window);

    // Draw the player's projectiles
    void drawProjectiles(sf::RenderWindow& window);
    
    // Move the player
    void move(float offsetX, float offsetY);

    // Set the player's position
    void setPlayerPosition(sf::Vector2f position);

    // Get the player's position
    // Overrides the Entity's getPosition method
    sf::Vector2f getPosition() const override;

    // Sets the player's direction
    void setDirection(float x, float y);

    // Get the player's direction
    sf::Vector2f getDirection() const;

    // Shoots a projectile when player clicks left mouse button
    void shootProjectiles(sf::Vector2f target);

    // Update the player's projectiles
    void updateProjectiles(const sf::View& view);
    
    // Update the player's position
    void calculateViewBoundaries(sf::Vector2f viewCenter, sf::Vector2f viewSize);

    // Set the player's maximum health
    void setMaxHealth(float maxHealth);

    // Set the player's current health
    void setCurrentHealth(float currentHealth);
};
