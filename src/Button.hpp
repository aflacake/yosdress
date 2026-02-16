#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <optional>

class Button {
public:
    Button(sf::Vector2f size, sf::Vector2f position, const std::string& label);

    bool isClicked(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
    std::optional<sf::Text> text;
    sf::Font font;
};
