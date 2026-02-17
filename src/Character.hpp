#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>

class Character {
public:
    Character();

    void attachHair(int index);
	void attachClothes(int index);
	void attachAccessory(int index);

    void draw(sf::RenderWindow& window);

    const std::vector<sf::Texture>& getHairTextures() const { return hairTextures; }
    const std::vector<sf::Texture>& getClothesTextures() const { return clothesTextures; }
    const std::vector<sf::Texture>& getAccessoryTextures() const { return accessoryTextures; }

    const std::optional<sf::Sprite>& getBody() const { return body; }

private:
    sf::Texture bodyTex;
    std::optional<sf::Sprite> body;

    std::vector<sf::Texture> hairTextures;
    std::optional<sf::Sprite> hair;

    std::vector<sf::Texture> clothesTextures;
    std::optional<sf::Sprite> clothes;

    std::vector<sf::Texture> accessoryTextures;
    std::optional<sf::Sprite> accessory;

    sf::Vector2f bodyPos; // hanya body
};
