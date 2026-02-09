#include "Button.hpp"

Button::Button(sf::Vector2f size, sf::Vector2f position) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color(100, 100, 255));
}

bool Button::isClicked(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        auto mouse = sf::Mouse::getPosition(window);
        sf::Vector2f mousePos(static_cast<float>(mouse.x),
                              static_cast<float>(mouse.y));

        if (shape.getGlobalBounds().contains(mousePos)) {
            return true;
        }
    }
    return false;
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
