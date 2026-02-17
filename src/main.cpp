#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Scene.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "YosDress");

    // Scene intro (musik + background + pose + tombol)
    Scene scene;
    scene.playMusic();

    Character character;

    // katalog hair/clothes/accessories
    std::vector<sf::Sprite> hairCatalog;
    for (int i = 0; i < character.getHairTextures().size(); ++i) {
        sf::Sprite s(character.getHairTextures()[i]);
        s.setPosition({600.f, 50.f + i * 100.f});
        hairCatalog.push_back(s);
    }

    std::vector<sf::Sprite> clothesCatalog;
    for (int i = 0; i < character.getClothesTextures().size(); ++i) {
        sf::Sprite s(character.getClothesTextures()[i]);
        s.setPosition({700.f, 50.f + i * 100.f});
        clothesCatalog.push_back(s);
    }

    std::vector<sf::Sprite> accessoryCatalog;
    for (int i = 0; i < character.getAccessoryTextures().size(); ++i) {
        sf::Sprite s(character.getAccessoryTextures()[i]);
        s.setPosition({750.f, 50.f + i * 100.f});
        accessoryCatalog.push_back(s);
    }

    sf::Sprite* dragged = nullptr;
    sf::Vector2f dragOffset;

    // intro state
    bool intro = true;

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (intro) {
				if (event->is<sf::Event::MouseButtonPressed>()) {
					auto mouse = sf::Mouse::getPosition(window);
					sf::Vector2f pos(mouse.x, mouse.y);

					bool startGame = false;
					scene.handleClick(pos, startGame);
					if (startGame) {
						intro = false; // keluar dari halaman sambutan, masuk ruang dress-up
					}
				}
			} else {
                if (event->is<sf::Event::MouseButtonPressed>()) {
                    auto mouse = sf::Mouse::getPosition(window);
                    sf::Vector2f pos(mouse.x, mouse.y);

                    for (auto& s : hairCatalog)
                        if (s.getGlobalBounds().contains(pos)) { dragged = &s; dragOffset = pos - s.getPosition(); }

                    for (auto& s : clothesCatalog)
                        if (s.getGlobalBounds().contains(pos)) { dragged = &s; dragOffset = pos - s.getPosition(); }

                    for (auto& s : accessoryCatalog)
                        if (s.getGlobalBounds().contains(pos)) { dragged = &s; dragOffset = pos - s.getPosition(); }
                }

                if (event->is<sf::Event::MouseButtonReleased>()) {
                    if (dragged) {
                        auto mouse = sf::Mouse::getPosition(window);
                        sf::Vector2f pos(mouse.x, mouse.y);

                        if (character.getBody()->getGlobalBounds().contains(pos)) {
							// cukup biarkan dragged di posisinya, jangan set ke bodyPos
						}
						dragged = nullptr;
                    }
                }

                if (event->is<sf::Event::MouseMoved>()) {
                    if (dragged) {
                        auto mouse = sf::Mouse::getPosition(window);
                        sf::Vector2f pos((float)mouse.x, (float)mouse.y);
                        dragged->setPosition(pos - dragOffset);
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        if (intro) {
            scene.drawIntro(window);
        } else {
            character.draw(window);
            for (auto& s : hairCatalog) window.draw(s);
            for (auto& s : clothesCatalog) window.draw(s);
            for (auto& s : accessoryCatalog) window.draw(s);
        }

        window.display();
    }
}
