#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Button.hpp"

int main() {
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "YosDress"
    );

    Character character;
	Button hairBtn({120.f, 40.f}, {600.f, 100.f});
    Button randomHairBtn({120.f, 40.f}, {600.f, 160.f});
    Button clothesBtn({120.f, 40.f}, {600.f, 220.f});
    Button accessoryBtn({120.f, 40.f}, {600.f, 280.f});

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (hairBtn.isClicked(window)) {
            character.nextHair();
        }
        if (randomHairBtn.isClicked(window)) {
            character.randomHair();
        }
        if (clothesBtn.isClicked(window)) {
            character.nextClothes();
        }
        if (accessoryBtn.isClicked(window)) {
            character.nextAccessory();
        }

        window.clear(sf::Color::White);
        character.draw(window);
        hairBtn.draw(window);
        window.display();
    }
}
