//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Player.hpp"

Player::Player() :
        healthBar(120.0f, 10.0f, sf::Color::Green) {

    shape.setRadius(playerRadius);
    shape.setFillColor(sf::Color::Blue);

    // Set max health and current health for the player
    healthBar.setMaxHealth(20.0f);
    healthBar.setCurrentHealth(20.0f);
}

void Player::draw(sf::RenderWindow& window) {
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

void Player::move(float x, float y) {
    shape.move(x, y);
}

void Player::setPlayerPosition(sf::Vector2f position) {
    shape.setPosition(position);
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}

void Player::shootProjectiles(sf::Vector2f target) {
    sf::Vector2f playerPosition = shape.getPosition();
    sf::Vector2f direction = target - playerPosition;

    float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);

    // This is to prevent division by zero (normalize the direction vector)
    if (magnitude != 0) {
        direction /= magnitude;
    }

    Projectile projectile;

    // This makes it so that the bullets 'spawn' from the center of the player's shape
    sf::Vector2f centerPosition = playerPosition + sf::Vector2f(shape.getRadius(), shape.getRadius());

    projectile.setPosition(centerPosition);
    projectile.setVelocity(direction * 0.2f);

    // After the player shoots a projectile, we keep track of it
    playerProjectiles.push_back(projectile);
}

void Player::updateProjectiles(const sf::View& view) {
    sf::Vector2f viewCenter = view.getCenter();
    sf::Vector2f viewSize = view.getSize();

    // Calculate view boundaries
    float left = viewCenter.x - viewSize.x / 2.0f;
    float right = viewCenter.x + viewSize.x / 2.0f;
    float top = viewCenter.y - viewSize.y / 2.0f;
    float bottom = viewCenter.y + viewSize.y / 2.0f;

    auto it = playerProjectiles.begin();

    // While the iterator hasn't reached the end of the vector
    while (it != playerProjectiles.end()) {
        it->updateProjectile();

        sf::Vector2f projPos = it->getPosition();

        bool outOfBoundsX = (projPos.x < left) || (projPos.x > right);
        bool outOfBoundsY = (projPos.y < top) || (projPos.y > bottom);

        if (outOfBoundsX || outOfBoundsY) {
            it = playerProjectiles.erase(it);
        } else {
            ++it;
        }
    }
}

void Player::drawProjectiles(sf::RenderWindow& window) {
    for (Projectile projectile: playerProjectiles) {
        projectile.draw(window);
    }
}

void Player::setDirection(float x, float y) {
    direction.x = x;
    direction.y = y;
}

sf::Vector2f Player::getDirection() const {
    return direction;
}

void Player::setMaxHealth(float maxHealth) {
    healthBar.setMaxHealth(maxHealth);
}

void Player::setCurrentHealth(float currentHealth) {
    healthBar.setCurrentHealth(currentHealth);
}