//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Projectile.hpp"

class Player {

private:

    float playerRadius = 20.f;

    sf::CircleShape playerShape;

    std::vector<Projectile> playerProjectiles;

public:

    // Constructor and Destructor

    Player();

    ~Player() = default;

    // Drawing methods

    void drawPlayer(sf::RenderWindow &window);

    void drawProjectiles(sf::RenderWindow &window);

    // Player Position-related methods

    void move(float offsetX, float offsetY);

    void setPlayerPosition(sf::Vector2f position);

    sf::Vector2f getPlayerPosition() const;

    // Projectile-related methods

    void shootProjectiles(sf::Vector2f target);

    void updateProjectiles(unsigned int windowWidth, unsigned int windowHeight);
};
