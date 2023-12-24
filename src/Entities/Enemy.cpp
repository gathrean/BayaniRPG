//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#include "Enemy.hpp"

Enemy::Enemy(float radius, float moveSpeed, const sf::Vector2f &playerPosition)
        : speed(moveSpeed), directionTowardsPlayer(playerPosition - sf::Vector2f(500.f, 500.f)) {

    enemyShape.setRadius(radius);
    enemyShape.setFillColor(sf::Color::Red);

    // Calculate the initial position outside the view (e.g., 500 pixels away from the player's position)
    enemyShape.setPosition(playerPosition + directionTowardsPlayer);
}

void Enemy::drawEnemy(sf::RenderWindow &window) {
    window.draw(enemyShape);
}

void Enemy::updatePosition(const sf::Vector2f &playerPosition) {
    sf::Vector2f directionTowardsPlayer = playerPosition - enemyShape.getPosition();

    // Ensure the enemy is far enough from the player before moving towards them
    const float minDistance = 50.0f; // Adjust this value according to your game's needs

    if (magnitude(directionTowardsPlayer) > minDistance) {
        normalize(directionTowardsPlayer);

        // Move the enemy towards the player
        enemyShape.move(directionTowardsPlayer * speed);
    }
}

float Enemy::magnitude(const sf::Vector2f &vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

void Enemy::normalize(sf::Vector2f &vector) {
    float vecMagnitude = magnitude(vector);
    if (vecMagnitude != 0) {
        vector /= vecMagnitude;
    }
}