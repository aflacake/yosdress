#include "Character.hpp"
#include <stdexcept>

Character::Character() {
    bodyPos = {200.f, 50.f};

    if (!bodyTex.loadFromFile("assets/body/base.png"))
        throw std::runtime_error("Failed to load body/base.png");
    body.emplace(bodyTex);
    body->setPosition(bodyPos);

    // load textures saja, jangan langsung emplace
    sf::Texture h1, h2, h3;
    if (!h1.loadFromFile("assets/hair/hair1.png"))
		throw std::runtime_error("Failed to load hair1.png");
	if (!h2.loadFromFile("assets/hair/hair2.png"))
		throw std::runtime_error("Failed to load hair2.png");
	if (!h3.loadFromFile("assets/hair/hair3.png"))
		throw std::runtime_error("Failed to load hair3.png");
    hairTextures.push_back(std::move(h1));
    hairTextures.push_back(std::move(h2));
    hairTextures.push_back(std::move(h3));

    sf::Texture c1, c2, c3;
    if (!c1.loadFromFile("assets/clothes/clothes1.png"))
		throw std::runtime_error("Failed to load clothes1.png");
	if (!c2.loadFromFile("assets/clothes/clothes2.png"))
		throw std::runtime_error("Failed to load clothes2.png");
	if (!c3.loadFromFile("assets/clothes/clothes3.png"))
		throw std::runtime_error("Failed to load clothes3.png");
    clothesTextures.push_back(std::move(c1));
    clothesTextures.push_back(std::move(c2));
    clothesTextures.push_back(std::move(c3));

    sf::Texture a1, a2, a3;
    if (!a1.loadFromFile("assets/accessories/acc1.png"))
		throw std::runtime_error("Failed to load acc1.png");
	if (!a2.loadFromFile("assets/accessories/acc2.png"))
		throw std::runtime_error("Failed to load acc2.png");
	if (!a3.loadFromFile("assets/accessories/acc3.png"))
		throw std::runtime_error("Failed to load acc3.png");
    accessoryTextures.push_back(std::move(a1));
    accessoryTextures.push_back(std::move(a2));
    accessoryTextures.push_back(std::move(a3));
}

void Character::attachHair(int index) {
    if (index < 0 || index >= hairTextures.size()) return;
    hair.emplace(hairTextures[index]);
    hair->setPosition(body->getPosition() + sf::Vector2f(0.f, -40.f));
}

void Character::attachClothes(int index) {
    if (index < 0 || index >= clothesTextures.size()) return;
    clothes.emplace(clothesTextures[index]);
    clothes->setPosition(body->getPosition());
}

void Character::attachAccessory(int index) {
    if (index < 0 || index >= accessoryTextures.size()) return;
    accessory.emplace(accessoryTextures[index]);
    accessory->setPosition(body->getPosition() + sf::Vector2f(40.f, -20.f));
}

void Character::draw(sf::RenderWindow& window) {
    if (body) window.draw(*body);
}
