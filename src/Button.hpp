#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
    Button(sf::Vector2f size, sf::Vector2f position);

    bool isClicked(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
};
