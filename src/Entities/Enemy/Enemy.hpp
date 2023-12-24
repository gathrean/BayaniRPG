//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Entity.hpp"
#include "../HealthBar/HealthBar.hpp"

class Enemy : public Entity {
private:

    sf::CircleShape shape;

    sf::Vector2f direction; // direction for enemy to follow

    float speed;

protected:

    HealthBar healthBar;

public:
    Enemy(float radius, float moveSpeed, const sf::Vector2f& playerPosition);

    void draw(sf::RenderWindow& window) override;

    void updatePosition(const sf::Vector2f& playerPosition);

    sf::Vector2f getPosition() const override;

    float magnitude(const sf::Vector2f& vector);

    void normalize(sf::Vector2f& vector);

    void setMaxHealth(float maxHealth);

    void setCurrentHealth(float currentHealth);

};
