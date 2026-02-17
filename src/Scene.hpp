#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <optional>

class Scene {
public:
    Scene();

    void playMusic();
	
    void drawIntro(sf::RenderWindow& window);
    void handleClick(sf::Vector2f mousePos, bool& startGame);

private:
    sf::Texture bgTex;
    std::optional<sf::Sprite> bg;

    sf::Texture boyTex;
    std::optional<sf::Sprite> boy;

    sf::Texture girlTex;
    std::optional<sf::Sprite> girl;

    sf::Music music;
	
    sf::Font fontBaloo;
    sf::Font fontArial;

    sf::RectangleShape playButton;
    std::optional<sf::Text> playText;

    sf::RectangleShape creditButton;
    std::optional<sf::Text> creditText;

    bool showCredit = false;
};
