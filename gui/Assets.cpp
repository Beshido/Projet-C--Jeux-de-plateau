#include "Assets.hpp"

sf::Texture Assets::trax = sf::Texture {};
sf::Texture Assets::carcassone = sf::Texture {};
sf::Texture Assets::dominoPanel = sf::Texture {};
sf::Texture Assets::traxPanel = sf::Texture {};
sf::Texture Assets::dominoBackground = sf::Texture {};
sf::Texture Assets::traxBackground = sf::Texture {};
sf::Texture Assets::carcassoneBackground = sf::Texture {};
sf::Texture Assets::carcassonePanel = sf::Texture {};
sf::Font Assets::font = sf::Font {};

const bool Assets::initializeAssets() {
    return trax.loadFromFile("./img/trax.jpg")
        && carcassone.loadFromFile("./img/carcassoneTuiles.png")
        && dominoPanel.loadFromFile("./img/dominoPanel.png")
        && traxPanel.loadFromFile("./img/traxPanel.png")
        && carcassonePanel.loadFromFile("./img/carcassonePanel.png")
        && dominoBackground.loadFromFile("./img/dominoBackground.jpg")        
        && traxBackground.loadFromFile("./img/traxBackground.jpg")        
        && carcassoneBackground.loadFromFile("./img/carcassoneBackground.jpg")                
        && font.loadFromFile("./fonts/SpaceMono-Regular.ttf");
}