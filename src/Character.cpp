#include "Character.hpp"
#include <stdexcept>

Character::Character() {
    if (!bodyTex.loadFromFile("assets/body/base.png"))
        throw std::runtime_error("Failed to load body/base.png");

    body.emplace(bodyTex);
    body->setPosition({200.f, 50.f});

    sf::Texture t1, t2, t3;
    if (!t1.loadFromFile("assets/hair/hair1.png"))
        throw std::runtime_error("Failed to load hair1.png");
    if (!t2.loadFromFile("assets/hair/hair2.png"))
        throw std::runtime_error("Failed to load hair2.png");
    if (!t3.loadFromFile("assets/hair/hair3.png"))
        throw std::runtime_error("Failed to load hair3.png");

    hairTextures.push_back(std::move(t1));
    hairTextures.push_back(std::move(t2));
    hairTextures.push_back(std::move(t3));

    hair.emplace(hairTextures[0]);
    hair->setPosition({200.f, 50.f});
}

void Character::nextHair() {
    if (hairTextures.empty()) return;

    currentHair = (currentHair + 1) % hairTextures.size();
    hair.emplace(hairTextures[currentHair]);
    hair->setPosition({200.f, 50.f});
}

void Character::draw(sf::RenderWindow& window) {
    if (body) window.draw(*body);
    if (hair) window.draw(*hair);
}
