#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>

class Character {
public:
    Character();

    void nextHair();
    void draw(sf::RenderWindow& window);

private:
    sf::Texture bodyTex;
    std::optional<sf::Sprite> body;

    std::vector<sf::Texture> hairTextures;
    std::optional<sf::Sprite> hair;

    int currentHair = 0;
};
