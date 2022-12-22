#include "DominoCarreGUI.hpp"
#include "DominoCarreTuileGUI.hpp"

DominoCarreGUI::DominoCarreGUI(DominoCarre* dominoCarre, sf::Font* font): dominoCarre { dominoCarre }, font { font }, dominoCarreTuilesGui { vector<vector<DominoCarreTuileGUI>>{} }, sacTuilesGui { Bouton { "Piocher", font } } {
    for (size_t x = 0; x < dominoCarre->getLongueur(); x++) {
        dominoCarreTuilesGui.push_back(vector<DominoCarreTuileGUI>());
        for (size_t y = 0; y < dominoCarre->getHauteur(); y++) {
            DominoCarreTuileGUI tuileGui { dominoCarre->getPlateau().at(x).at(y), font };
            tuileGui.setPosition(x * tuileGui.getTaille(), y * tuileGui.getTaille());
            dominoCarreTuilesGui.at(x).push_back(tuileGui);
        }
    }
}

void DominoCarreGUI::setSize(const float size) {
    sacTuilesGui.setSize(size, size / 1.5f);
    sacTuilesGui.setOrigin(sacTuilesGui.getSize());

    const int sizeTuile = std::min(size / dominoCarre->getLongueur(), size / dominoCarre->getHauteur());
    for (size_t x = 0; x < dominoCarre->getLongueur(); x++) {
        for (size_t y = 0; y < dominoCarre->getHauteur(); y++) {
            dominoCarreTuilesGui.at(x).at(y).setSize(sizeTuile);
            dominoCarreTuilesGui.at(x).at(y).setPosition(x * sizeTuile, y * sizeTuile);
        }
    }
}

void DominoCarreGUI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(sacTuilesGui, states);
    for (size_t x = 0; x < dominoCarre->getLongueur(); x++) {
        for (size_t y = 0; y < dominoCarre->getHauteur(); y++) {
            target.draw(dominoCarreTuilesGui.at(x).at(y), states);
        }
    }
}