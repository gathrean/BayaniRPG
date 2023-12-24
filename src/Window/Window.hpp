//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Entities/Player.hpp"

class Window {

private:
    sf::RenderWindow window;

    // Singleton
    Window(unsigned int width, unsigned int height, const std::string &title)
            : window(sf::VideoMode(width, height), title, sf::Style::Resize) {}

    void drawCheckeredBackground();

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