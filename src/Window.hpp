//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#pragma once

#include <SFML/Graphics.hpp>

class Window {

private:
    // The window object
    sf::RenderWindow window;

public:
    // Constructor
    Window(unsigned int width, unsigned int height, const std::string &title)
            : window(sf::VideoMode(width, height), title, sf::Style::Resize) {}

    // Check if the window is open
    bool isOpen() const;

    // Clear the window
    void clear();

    // Display the window
    void display();

    // Close the window
    void close();

    // Draw a drawable object
    void draw(const sf::Drawable &drawable);

    // Get the window object
    sf::RenderWindow &getWindow();
};