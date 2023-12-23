//
// Created by Gathrean Dela Cruz on 2023-12-22.
//

#include "Window.hpp"

bool Window::isOpen() const {
    return window.isOpen();
}

void Window::clear() {
    window.clear();
}

void Window::display() {
    window.display();
}

void Window::close() {
    window.close();
}

void Window::draw(const sf::Drawable &drawable) {
    window.draw(drawable);
}

sf::RenderWindow &Window::getWindow() {
    return window;
}