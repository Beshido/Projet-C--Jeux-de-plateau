#include "Assets.hpp"

sf::Texture Assets::mainBackground = sf::Texture {};
sf::Texture Assets::plateauBackground = sf::Texture {};
sf::Texture Assets::trax = sf::Texture {};
sf::Texture Assets::carcassone = sf::Texture {};
sf::Font Assets::font = sf::Font {};

const bool Assets::initializeAssets() {
    return mainBackground.loadFromFile("./img/fleurs.png")
        && plateauBackground.loadFromFile("./img/domino_background.jpg")
        && trax.loadFromFile("./img/trax.jpg")
        && carcassone.loadFromFile("./img/carcassoneTuiles.png")
        && font.loadFromFile("./fonts/SpaceMono-Regular.ttf");
}