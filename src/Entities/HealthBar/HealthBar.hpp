//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#pragma once

#include <SFML/Graphics.hpp>

class HealthBar {

private:

    sf::RectangleShape bar;
    sf::RectangleShape outline;

    float maxWidth;

    float currentHealth;

public:

    HealthBar(float width, float height);

    void setPosition(const sf::Vector2f& position);

    void setMaxHealth(float maxHealth);

    void setCurrentHealth(float currentHealth);

    void update();

    void draw(sf::RenderWindow& window);
};

