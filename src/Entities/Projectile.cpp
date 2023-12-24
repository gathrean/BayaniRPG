//
// Created by Gathrean Dela Cruz on 2023-12-23.
//

#include "Projectile.hpp"

Projectile::Projectile() {
    projectile.setRadius(projectileRadius);
    projectile.setFillColor(sf::Color::Red);
}

void Projectile::updateProjectile() {
    projectile.move(velocity);
}

void Projectile::drawProjectile(sf::RenderWindow &window) {
    window.draw(projectile);
}

sf::Vector2f Projectile::getPosition() const {
    return projectile.getPosition();
}

void Projectile::setPosition(sf::Vector2f position) {
    projectile.setPosition(position);
}

void Projectile::setVelocity(sf::Vector2f vel) {
    velocity = vel;
}