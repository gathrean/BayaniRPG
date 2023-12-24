//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Player.hpp"

Player::Player() {
    playerShape.setRadius(playerRadius);
    playerShape.setFillColor(sf::Color::Cyan);
}

void Player::drawPlayer(sf::RenderWindow &window) {
    window.draw(playerShape);
}

void Player::move(float x, float y) {
    playerShape.move(x, y);
}

void Player::setPlayerPosition(sf::Vector2f position) {
    playerShape.setPosition(position);
}

sf::Vector2f Player::getPlayerPosition() const {
    return playerShape.getPosition();
}

void Player::shootProjectiles(sf::Vector2f target) {
    sf::Vector2f playerPosition = playerShape.getPosition();
    sf::Vector2f direction = target - playerPosition;

    float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);

    // This is to prevent division by zero (normalize the direction vector)
    if (magnitude != 0) {
        direction /= magnitude;
    }

    Projectile projectile;

    // This makes it so that the bullets 'spawn' from the center of the player's shape
    sf::Vector2f centerPosition = playerPosition + sf::Vector2f(playerShape.getRadius(), playerShape.getRadius());

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

void Player::drawProjectiles(sf::RenderWindow &window) {
    for (Projectile projectile: playerProjectiles) {
        projectile.drawProjectile(window);
    }
}

void Player::setDirection(float x, float y) {
    direction.x = x;
    direction.y = y;
}

sf::Vector2f Player::getDirection() const {
    return direction;
}