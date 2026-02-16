#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Button.hpp"

int main() {
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "YosDress"
    );

    // set icon segera setelah window dibuat
    sf::Image icon;
    if (icon.loadFromFile("assets/ui/icon.png")) {
        window.setIcon(icon);
    }

    Character character;

    // deklarasi tombol
    Button hairBtn({120.f, 40.f}, {600.f, 100.f}, "Change Hair");
    Button randomHairBtn({120.f, 40.f}, {600.f, 160.f}, "Random Hair");
    Button clothesBtn({120.f, 40.f}, {600.f, 220.f}, "Change Clothes");
    Button accessoryBtn({120.f, 40.f}, {600.f, 280.f}, "Change Accessory");
    Button fullscreenBtn({120.f, 40.f}, {600.f, 340.f}, "Toggle Fullscreen");
    Button scaleBtn({120.f, 40.f}, {600.f, 400.f}, "Scale Resolution");

    while (window.isOpen()) {
        // event loop
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
		
		// state fullscreen manual
		static bool isFullscreen = false;
		static bool scaled = false;

        // tombol interaksi
		if (hairBtn.isClicked(window)) character.nextHair();
		if (randomHairBtn.isClicked(window)) character.randomHair();
		if (clothesBtn.isClicked(window)) character.nextClothes();
		if (accessoryBtn.isClicked(window)) character.nextAccessory();

        if (fullscreenBtn.isClicked(window)) {
			if (!isFullscreen) {
				window.create(sf::VideoMode::getFullscreenModes()[0], "YosDress", sf::State::Fullscreen);
				isFullscreen = true;
			} else {
				window.create(sf::VideoMode({800, 600}), "YosDress", sf::State::Windowed);
				isFullscreen = false;
			}
		}

        if (scaleBtn.isClicked(window)) {
			if (!scaled) {
				window.create(sf::VideoMode({1280, 720}), "YosDress", sf::State::Windowed);
				scaled = true;
			} else {
				window.create(sf::VideoMode({800, 600}), "YosDress", sf::State::Windowed);
				scaled = false;
			}
		}

        // output (render)
        window.clear(sf::Color::White);
        character.draw(window);
        hairBtn.draw(window);
        randomHairBtn.draw(window);
        clothesBtn.draw(window);
        accessoryBtn.draw(window);
        fullscreenBtn.draw(window);
        scaleBtn.draw(window);
        window.display();
    }
}
