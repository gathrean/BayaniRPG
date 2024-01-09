//
// Created by Gathrean Dela Cruz on 2023-12-29.
//

#pragma once

#include <string>

/**
 * Constants namespace
 */
namespace GameConstants {
    
    // Window title
    const std::string WINDOW_TITLE = "Bayani RPG";
    
    // Window width
    static constexpr unsigned int WINDOW_WIDTH = 1200;
    
    // Window height
    static constexpr unsigned int WINDOW_HEIGHT = 800;
    
    // Player movement speed
    static constexpr float PLAYER_MOVEMENT_SPEED = 0.05f;
    
    // Enemy spawn interval
    static constexpr float ENEMY_SPAWN_INTERVAL = 5.0f;
}