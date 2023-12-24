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

    sf::View view;

    std::string backgroundFileName = "../media/deepslate.png";

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

        // Set an initial view for the window
        view.setSize(static_cast<float>(width), static_cast<float>(height));
        view.setCenter(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
        window.setView(view);
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

    // Add a method to apply the zoom-out effect
    void applyZoomOut(float factor) {
        sf::Vector2f newSize = view.getSize() * factor;
        view.setSize(newSize);
        window.setView(view);
    }

    // Destructor
    ~Window() { window.close(); }
};