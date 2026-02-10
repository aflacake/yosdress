#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>

class Character {
public:
    Character();

    void nextHair();
    void randomHair();
    void nextClothes();
    void nextAccessory();
    void draw(sf::RenderWindow& window);

private:
    sf::Texture bodyTex;
    std::optional<sf::Sprite> body;

    std::vector<sf::Texture> hairTextures;
    std::optional<sf::Sprite> hair;
    int currentHair = 0;

    std::vector<sf::Texture> clothesTextures;
    std::optional<sf::Sprite> clothes;
    int currentClothes = 0;

    std::vector<sf::Texture> accessoryTextures;
    std::optional<sf::Sprite> accessory;
    int currentAccessory = 0;
};
