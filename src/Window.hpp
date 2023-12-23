//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#pragma once

#include <SFML/Graphics.hpp>

class Window {
private:
    // Private constructor to prevent external instantiation
    Window(unsigned int width, unsigned int height, const std::string &title)
            : window(sf::VideoMode(width, height), title, sf::Style::Resize) {}

    // Draw the checkered background
    void drawCheckeredBackground() {
        constexpr int tileSize = 50; // Size of each tile
        sf::RectangleShape tile;
        tile.setSize(sf::Vector2f(tileSize, tileSize));

        bool isWhite = true;
        for (int y = 0; y < window.getSize().y; y += tileSize) {
            isWhite = !isWhite; // Alternate the pattern
            for (int x = 0; x < window.getSize().x; x += tileSize) {
                tile.setPosition(static_cast<float>(x), static_cast<float>(y));
                tile.setFillColor(isWhite ? sf::Color::Blue : sf::Color::Black);
                window.draw(tile);
                isWhite = !isWhite; // Switch color for the next tile
            }
        }
    }

    // The window object
    sf::RenderWindow window;

public:
    // Deleted copy constructor and copy assignment operator
    Window(const Window &) = delete;

    Window &operator=(const Window &) = delete;

    // Destructor
    ~Window() {
        window.close();
    }

    // Function to get the singleton instance of Window
    static Window &getInstance(unsigned int width, unsigned int height, const std::string &title) {
        static Window instance(width, height, title); // Static instance of Window
        return instance;
    }

    // Check if the window is open
    inline bool isOpen() const {
        return window.isOpen();
    }

    // Clear the window
    inline void clear() {
        window.clear();
    }

    // Display the window
    inline void display() {
        window.display();
    }

    // Close the window
    inline void close() {
        window.close();
    }

    // Draw a drawable object
    inline void draw(const sf::Drawable &drawable) {
        drawCheckeredBackground();
        window.draw(drawable);
    }

    // Get the window object
    inline sf::RenderWindow &getWindow() {
        return window;
    }
};