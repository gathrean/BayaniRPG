//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Projectile/Projectile.hpp"
#include "../Entity.hpp"

class Player : public Entity {

private:

    float playerRadius = 20.f;

    sf::CircleShape playerShape;

    std::vector<Projectile> playerProjectiles;

    sf::Vector2f direction;

public:

    // Constructor and Destructor

    Player();

    ~Player() override = default;

    // Drawing methods

    void draw(sf::RenderWindow& window) override;

    void drawProjectiles(sf::RenderWindow& window);

    // Player Position-related methods

    void move(float offsetX, float offsetY);

    void setPlayerPosition(sf::Vector2f position);

    sf::Vector2f getPosition() const override;

    // Direction-related methods
    void setDirection(float x, float y);

    sf::Vector2f getDirection() const;

    // Projectile-related methods

    void shootProjectiles(sf::Vector2f target);

    void updateProjectiles(const sf::View& view);
};
