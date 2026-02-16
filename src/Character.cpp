#include "Character.hpp"
#include <stdexcept>
#include <cstdlib>

Character::Character() {
    // Posisi dasar body
    sf::Vector2f bodyPos = {200.f, 50.f};
    sf::Vector2f hairOffset = {0.f, -40.f};       // rambut lebih tinggi
    sf::Vector2f clothesOffset = {0.f, 0.f};      // baju sama dengan body
    sf::Vector2f accessoryOffset = {40.f, -20.f}; // contoh: aksesoris di kepala kanan

    // Body
    if (!bodyTex.loadFromFile("assets/body/base.png"))
        throw std::runtime_error("Failed to load body/base.png");
    body.emplace(bodyTex);
    body->setPosition(bodyPos);

    // Hair
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
    hair.emplace(hairTextures[0]);
    hair->setPosition(bodyPos + hairOffset);

    // Clothes
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
    clothes.emplace(clothesTextures[0]);
    clothes->setPosition(bodyPos + clothesOffset);

    // Accessories
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
    accessory.emplace(accessoryTextures[0]);
    accessory->setPosition(bodyPos + accessoryOffset);

    // Simpan offset agar bisa dipakai di fungsi lain
    this->bodyPos = bodyPos;
    this->hairOffset = hairOffset;
    this->clothesOffset = clothesOffset;
    this->accessoryOffset = accessoryOffset;
}

void Character::nextHair() {
    if (hairTextures.empty()) return;
    currentHair = (currentHair + 1) % hairTextures.size();
    hair.emplace(hairTextures[currentHair]);
    hair->setPosition(bodyPos + hairOffset);
}

void Character::randomHair() {
    if (hairTextures.empty()) return;
    currentHair = std::rand() % hairTextures.size();
    hair.emplace(hairTextures[currentHair]);
    hair->setPosition(bodyPos + hairOffset);
}

void Character::nextClothes() {
    if (clothesTextures.empty()) return;
    currentClothes = (currentClothes + 1) % clothesTextures.size();
    clothes.emplace(clothesTextures[currentClothes]);
    clothes->setPosition(bodyPos + clothesOffset);
}

void Character::nextAccessory() {
    if (accessoryTextures.empty()) return;
    currentAccessory = (currentAccessory + 1) % accessoryTextures.size();
    accessory.emplace(accessoryTextures[currentAccessory]);
    accessory->setPosition(bodyPos + accessoryOffset);
}

void Character::draw(sf::RenderWindow& window) {
    if (body) window.draw(*body);
    if (clothes) window.draw(*clothes);
    if (hair) window.draw(*hair);
    if (accessory) window.draw(*accessory);
}
