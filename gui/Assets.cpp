#include "Assets.hpp"

sf::Texture Assets::mainBackground = sf::Texture {};
sf::Texture Assets::plateauBackground = sf::Texture {};
sf::Texture Assets::trax = sf::Texture {};
sf::Texture Assets::carcassone = sf::Texture {};
sf::Texture Assets::dominoPanel = sf::Texture {};
sf::Texture Assets::traxPanel = sf::Texture {};
sf::Texture Assets::carcassonePanel = sf::Texture {};
sf::Font Assets::font = sf::Font {};

const bool Assets::initializeAssets() {
    return mainBackground.loadFromFile("./img/fleurs.png")
        && plateauBackground.loadFromFile("./img/domino_background.jpg")
        && trax.loadFromFile("./img/trax.jpg")
        && carcassone.loadFromFile("./img/carcassoneTuiles.png")
        && dominoPanel.loadFromFile("./img/dominoPanel.png")
        && traxPanel.loadFromFile("./img/traxPanel.png")
        && carcassonePanel.loadFromFile("./img/carcassonePanel.png")
        && font.loadFromFile("./fonts/SpaceMono-Regular.ttf");
}