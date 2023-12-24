//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#pragma once

#include <SFML/Graphics.hpp>

class Enemy {
private:

    sf::CircleShape enemyShape;

    sf::Vector2f directionTowardsPlayer; // direction for enemy to follow

    float speed;

public:
    Enemy(float radius, float moveSpeed, const sf::Vector2f &playerPosition);

    void drawEnemy(sf::RenderWindow &window);

    void updatePosition(const sf::Vector2f &playerPosition);

    float magnitude(const sf::Vector2f &vector);

    void normalize(sf::Vector2f &vector);

};

