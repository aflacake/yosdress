#include "Scene.hpp"
#include <stdexcept>

Scene::Scene() {
    if (!bgTex.loadFromFile("assets/ui/bg.png"))
        throw std::runtime_error("Failed to load bg.png");
    bg.emplace(bgTex);
    bg->setPosition({0.f, 0.f});

    if (!boyTex.loadFromFile("assets/ui/pose-boy.png"))
        throw std::runtime_error("Failed to load pose-boy.png");
    boy.emplace(boyTex);
    boy->setPosition({150.f, 200.f});

    if (!girlTex.loadFromFile("assets/ui/pose-girl.png"))
        throw std::runtime_error("Failed to load pose-girl.png");
    girl.emplace(girlTex);
    girl->setPosition({450.f, 200.f});

    if (!music.openFromFile("assets/music/poorkidmusic-kawaii-drops-no-copy-right-386533.mp3"))
        throw std::runtime_error("Failed to load intro music");
	
    if (!fontBaloo.openFromFile("assets/ui/baloo2.ttf"))
        throw std::runtime_error("Failed to load baloo2.ttf");
    if (!fontArial.openFromFile("assets/ui/arial.TTF"))
        throw std::runtime_error("Failed to load arial.TTF");

    // scale background to window size (800x600)
	bg->setScale(sf::Vector2f(
		800.f / bg->getLocalBounds().size.x,
		600.f / bg->getLocalBounds().size.y
	));
	
    // Play button
    playButton.setSize({200.f, 60.f});
    playButton.setFillColor(sf::Color(232, 180, 184)); // #E8B4B8
    playButton.setPosition({300.f, 500.f});
    playText.emplace(fontBaloo, "Play", 32);
    playText->setFillColor(sf::Color(75, 59, 64)); // #4B3B40
    playText->setPosition({370.f, 510.f});

    // Credit button
    creditButton.setSize({120.f, 40.f});
    creditButton.setFillColor(sf::Color(232, 180, 184));
    creditButton.setPosition({20.f, 540.f});
	creditText.emplace(fontArial, "Credit", 20);
	creditText->setFillColor(sf::Color(75, 59, 64));
	creditText->setPosition({40.f, 545.f});
}

void Scene::drawIntro(sf::RenderWindow& window) {
    if (bg) window.draw(*bg);
    if (boy) window.draw(*boy);
    if (girl) window.draw(*girl);

    window.draw(playButton);
    if (playText) window.draw(*playText);
    window.draw(creditButton);
    if (creditText) window.draw(*creditText);

    if (showCredit) {
        sf::Text creditInfo(fontArial, "Music by Abhishek M from Pixabay", 18);
        creditInfo.setFillColor(sf::Color::Black);
        creditInfo.setPosition({200.f, 560.f});
        window.draw(creditInfo);
    }
}

void Scene::handleClick(sf::Vector2f mousePos, bool& startGame) {
    if (playButton.getGlobalBounds().contains(mousePos)) {
        startGame = true;
    }
    if (creditButton.getGlobalBounds().contains(mousePos)) {
        showCredit = !showCredit;
    }
}

void Scene::playMusic() {
    music.setLooping(true);
    music.play();
}
