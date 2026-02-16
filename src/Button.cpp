#include "Button.hpp"
#include <stdexcept>

Button::Button(sf::Vector2f size, sf::Vector2f position, const std::string& label) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color(232, 180, 184)); // pink #E8B4B8

    if (!font.openFromFile("assets/ui/arial.ttf"))
		throw std::runtime_error("Failed to load font arial.ttf");

    // Konstruktor sf::Text di SFML 3: (Font&, String, size)
    text.emplace(font, label, 16);
	text->setFillColor(sf::Color(75, 59, 64));
	text->setPosition({position.x + 10.f, position.y + 10.f});
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
    if (text) window.draw(*text);
}
