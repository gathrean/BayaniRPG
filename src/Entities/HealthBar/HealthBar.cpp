//
// Created by Gathrean Dela Cruz on 2023-12-24.
//

#include "HealthBar.hpp"

HealthBar::HealthBar(float width, float height) {
    this->bar.setSize(sf::Vector2f(width, height));
    this->outline.setSize(sf::Vector2f(width, height));
    this->outline.setFillColor(sf::Color::Transparent);
    this->outline.setOutlineColor(sf::Color::Black);
    this->outline.setOutlineThickness(1.0f);
    this->maxWidth = width;
    this->currentHealth = 100.0f;
}

void HealthBar::setPosition(const sf::Vector2f& position) {
    this->bar.setPosition(position);
    this->outline.setPosition(position);
}

void HealthBar::setMaxHealth(float maxHealth) {
    this->maxWidth = maxHealth;
}

void HealthBar::setCurrentHealth(float currentHealth) {
    this->currentHealth = currentHealth;
}

void HealthBar::update() {
    float healthPercentage = this->currentHealth / this->maxWidth;
    this->bar.setSize(sf::Vector2f(this->maxWidth * healthPercentage, this->bar.getSize().y));
}

void HealthBar::draw(sf::RenderWindow& window) {
    window.draw(this->outline);
    window.draw(this->bar);
}