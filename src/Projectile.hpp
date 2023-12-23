//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#pragma once

#include <SFML/Graphics.hpp>

class Projectile {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;

public:
    Projectile(float radius = 5.f) {
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Red);
    }

    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }

    void setPosition(sf::Vector2f position) {
        shape.setPosition(position);
    }

    void setVelocity(sf::Vector2f vel) {
        velocity = vel;
    }

    void update() {
        shape.move(velocity);
    }

    void draw(sf::RenderWindow &window) {
        window.draw(shape);
    }
};
