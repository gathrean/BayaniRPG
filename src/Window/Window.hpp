//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Entities/Player.hpp"

class Window {

private:
    sf::RenderWindow window;

    sf::Texture backgroundTexture; // Add a texture for the background
    sf::Sprite backgroundSprite; // Add a sprite to render the background texture

    std::string backgroundFileName = "../media/deep_slate.jpg";

    float backgroundX = 0.0f;
    float backgroundY = 0.0f;

    // Singleton
    Window(unsigned int width, unsigned int height, const std::string &title)
            : window(sf::VideoMode(width, height), title, sf::Style::Resize) {

        bool isBackgroundLoaded = backgroundTexture.loadFromFile(backgroundFileName);

        if (isBackgroundLoaded) {
            backgroundSprite.setTexture(backgroundTexture); // Set the texture for the sprite
        } else {
            // Handle error when loading the background texture
            std::cout << "Failed to load background texture!" << std::endl;
        }
    }


public:
    // Singleton instance getter
    static Window &getInstance(unsigned int width, unsigned int height, const std::string &title) {
        static Window instance(width, height, title);
        return instance;
    }

    void drawWindow(Player player);

    inline void displayWindow() { window.display(); }

    inline void clearWindowContents() { window.clear(); }

    inline void closeWindow() { window.close(); }

    inline bool isWindowOpen() const { return window.isOpen(); }

    inline sf::RenderWindow &getWindow() { return window; }

    // Singleton: deleted copy constructor
    Window(const Window &) = delete;

    // Singleton: deleted assignment operator
    Window &operator=(const Window &) = delete;

    // Destructor
    ~Window() { window.close(); }
};