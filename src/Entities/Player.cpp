//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Player.hpp"

Player::Player() {
    shape.setRadius(playerRadius);
    shape.setFillColor(sf::Color::Green);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

void Player::move(float x, float y) {
    shape.move(x, y);
}

void Player::setPlayerPosition(sf::Vector2f position) {
    shape.setPosition(position);
}

sf::Vector2f Player::getPlayerPosition() const {
    return shape.getPosition();
}

void Player::shootProjectiles(sf::Vector2f target) {
    sf::Vector2f playerPos = shape.getPosition();
    sf::Vector2f direction = target - playerPos;

    float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (magnitude != 0) {
        direction /= magnitude; // Normalize the direction vector
    }

    // Calculate the position of the center of the player's shape
    sf::Vector2f centerPos = playerPos + sf::Vector2f(shape.getRadius(), shape.getRadius());

    // Adjust the projectile starting position relative to the center of the player's shape
    Projectile projectile;
    projectile.setPosition(centerPos);
    projectile.setVelocity(direction * 0.2f); // Set the velocity of the projectile

    playerProjectiles.push_back(projectile); // Add the projectile to the vector
}

void Player::updateProjectiles(unsigned int windowWidth, unsigned int windowHeight) {
    for (size_t i = 0; i < playerProjectiles.size(); ++i) {
        playerProjectiles[i].update();

        // Remove projectiles that are out of bounds
        sf::Vector2f projPos = playerProjectiles[i].getPosition();
        if (projPos.x < 0 || projPos.x > windowWidth || projPos.y < 0 || projPos.y > windowHeight) {
            playerProjectiles.erase(playerProjectiles.begin() + i);
            --i;
        }
    }
}

void Player::drawProjectiles(sf::RenderWindow &window) {
    for (Projectile projectile: playerProjectiles) {
        projectile.draw(window);
    }
}