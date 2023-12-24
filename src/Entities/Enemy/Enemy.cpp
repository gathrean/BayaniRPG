//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#include "Enemy.hpp"

Enemy::Enemy(float radius, float moveSpeed, const sf::Vector2f& playerPosition)
        : speed(moveSpeed) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Red);

    // Calculate the initial position outside the view (e.g., 500 pixels away from the player's position)
    sf::Vector2f direction = playerPosition - sf::Vector2f(500.f, 500.f); // Example offset

    // Normalize the direction vector
    float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (magnitude != 0) {
        direction /= magnitude;
    }

    // Set the enemy's position outside the view by a distance (e.g., 500 pixels away from the player)
    shape.setPosition(playerPosition + direction * 500.f);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(shape);
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