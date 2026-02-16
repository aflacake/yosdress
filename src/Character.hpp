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
    // Textures & sprites
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

    // Posisi dasar dan offset
    sf::Vector2f bodyPos;        // posisi dasar body
    sf::Vector2f hairOffset;     // offset relatif untuk hair
    sf::Vector2f clothesOffset;  // offset relatif untuk clothes
    sf::Vector2f accessoryOffset;// offset relatif untuk accessories
};
