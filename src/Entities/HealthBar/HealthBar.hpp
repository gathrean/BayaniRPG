//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#pragma once

#include <SFML/Graphics.hpp>

class HealthBar {

private:
    
    // The outline of the health bar
    sf::RectangleShape outline;
    
    // The fill of the health bar
    float maxWidth;
    
    // The current health of the entity
    float currentHealth;

public:
    
    // The bar of the health bar
    sf::RectangleShape bar;
    
    // Constructor
    HealthBar(float width, float height, sf::Color fillColor);
    
    // Draw the health bar
    void draw(sf::RenderWindow& window);
    
    // Update the health bar
    void update();
    
    // Set the position of the health bar
    void setPosition(const sf::Vector2f& position);
    
    // Set the maximum health of the entity
    void setMaxHealth(float maxHealth);
    
    // Set the current health of the entity
    void setCurrentHealth(float currentHealth);
};

