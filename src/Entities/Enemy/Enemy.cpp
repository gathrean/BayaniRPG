//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#include "Enemy.hpp"

Enemy::Enemy(float radius, float moveSpeed, const sf::Vector2f& playerPosition)
        : speed(moveSpeed),
          direction(playerPosition - sf::Vector2f(500.f, 500.f)),
          healthBar(60.0f, 10.0f, sf::Color::Red) {

    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Magenta);

    // Calculate the initial position outside the view (e.g., 500 pixels away from the player's position)
    shape.setPosition(playerPosition + direction);

    // Set max health and current health for the enemy
    healthBar.setMaxHealth(5.0f);
    healthBar.setCurrentHealth(5.0f);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(shape);

// Calculate the position for the health bar below the player
    sf::Vector2f healthBarPosition = shape.getPosition();
    // Calculate the adjustment to center the health bar
    float healthBarOffsetX = (shape.getGlobalBounds().width - healthBar.bar.getSize().x) / 2.0f;
    float healthBarOffsetY = shape.getRadius() * 2.25f;
    healthBarPosition.x += healthBarOffsetX;
    healthBarPosition.y += healthBarOffsetY;

    // Set the position of the health bar
    healthBar.setPosition(healthBarPosition);

    // Draw the health bar for the player
    healthBar.draw(window);
}

void Enemy::updatePosition(const sf::Vector2f& playerPosition) {
    sf::Vector2f directionTowardsPlayer = playerPosition - shape.getPosition();

    // Ensure the enemy is far enough from the player before moving towards them
    const float minDistance = 50.0f; // Adjust this value according to your game's needs

    if (magnitude(directionTowardsPlayer) > minDistance) {
        normalize(directionTowardsPlayer);

        // Move the enemy towards the player
        shape.move(directionTowardsPlayer * speed);
    }
}

sf::Vector2f Enemy::getPosition() const {
    return shape.getPosition();
}

float Enemy::magnitude(const sf::Vector2f& vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

void Enemy::normalize(sf::Vector2f& vector) {
    float vecMagnitude = magnitude(vector);
    if (vecMagnitude != 0) {
        vector /= vecMagnitude;
    }
}

void Enemy::setMaxHealth(float maxHealth) {
    healthBar.setMaxHealth(maxHealth);
}

void Enemy::setCurrentHealth(float currentHealth) {
    healthBar.setCurrentHealth(currentHealth);
}