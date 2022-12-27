#include "DominoCarreGUI.hpp"
#include "DominoCarreTuileGUI.hpp"

DominoCarreGUI::DominoCarreGUI(DominoCarre* dominoCarre, const sf::Font* font): dominoCarre { dominoCarre }, font { font }, dominoCarreTuilesGui { std::vector<std::vector<DominoCarreTuileGUI*>>{} }, sacTuilesGui { Bouton { "Piocher", font } } {
    for (size_t x = 0; x < dominoCarre->getWidth(); x++) {
        dominoCarreTuilesGui.push_back(std::vector<DominoCarreTuileGUI*>{});
        for (size_t y = 0; y < dominoCarre->getHeight(); y++) {
            DominoCarreTuile* tuile = dominoCarre->getPlateau().at(x).at(y);
            DominoCarreTuileGUI* tuilePtr = nullptr;
            if (tuile != nullptr) {
                tuilePtr = new DominoCarreTuileGUI { tuile, font };
                tuilePtr->setPosition(x * tuilePtr->getCarre()->getSize().x, y * tuilePtr->getCarre()->getSize().y);
            }
            dominoCarreTuilesGui.at(x).push_back(tuilePtr);
        }
    }
    sacTuilesGui.setOnClickListener(std::bind(&DominoCarreGUI::onSacTuileClick, this));
    tuilePioche = nullptr;
    for (size_t i = 0; i < dominoCarre->getPlayers().size(); i++) {
        joueursGui.push_back(DominoCarreJoueurGUI { dominoCarre->getPlayers().at(i), font });
    }
}

void DominoCarreGUI::setSize(const sf::Vector2u size) {
    const unsigned int sizeTuile = size.y / dominoCarre->getHeight();
    for (size_t i = 0; i < dominoCarre->getWidth(); i++) {
        for (size_t j = 0; j < dominoCarre->getHeight(); j++) {
            if (!dominoCarreTuilesGui.at(i).at(j))
                continue;
            dominoCarreTuilesGui.at(i).at(j)->setSize(sizeTuile);
            dominoCarreTuilesGui.at(i).at(j)->setPosition(i * sizeTuile, j * sizeTuile);
        }
    }
    sacTuilesGui.setSize(size.x * 20 / 100, size.y * 10 / 100);
    sacTuilesGui.setPosition(dominoCarre->getWidth() * sizeTuile, 0);
    if (tuilePioche != nullptr) {
        tuilePioche->setSize(sizeTuile);
        tuilePioche->setPosition(dominoCarre->getWidth() * sizeTuile, size.y * 10 / 100);
    }
    for (size_t i = 0; i < joueursGui.size(); i++) {
        joueursGui.at(i).setSize(size.x * 20 / 100, size.y * 10 / 100);
        joueursGui.at(i).setPosition(dominoCarre->getWidth() * sizeTuile, (size.y * 10 / 100 + sizeTuile) * (i + 1));
    }

    this->size = size;
}

void DominoCarreGUI::setSize(const unsigned int x, const unsigned int y) {
    setSize(sf::Vector2u { x, y });
}

const bool DominoCarreGUI::onSacTuileClick() {
    std::cout << "Bouton sac de tuile cliqué." << std::endl;

    DominoCarreTuile* tuile = dominoCarre->drawTile();
    tuilePioche = new DominoCarreTuileGUI { tuile, font };

    const unsigned int sizeTuile = size.y / dominoCarre->getHeight();
    tuilePioche->setSize(sizeTuile);
    tuilePioche->setPosition(dominoCarre->getWidth() * sizeTuile, size.y * 10 / 100);
    return true;
}

const bool DominoCarreGUI::fireEvent(const sf::Event::MouseButtonEvent event) {
    if (sacTuilesGui.isClicked(event.x, event.y)) {
        sacTuilesGui.fireEvent();
    }
    else if (tuilePioche && tuilePioche->isClicked(event.x, event.y)) {
        switch (event.button) {
            case sf::Mouse::Left:
                std::cout << "Rotaiton gauche." << std::endl;
                tuilePioche->getTuile()->tournerGauche();
                tuilePioche->updateValues();
                break;
            case sf::Mouse::Right:
                std::cout << "Rotaiton droite." << std::endl;
                tuilePioche->getTuile()->tournerDroite();
                tuilePioche->updateValues();
                break;
            default:
                break;
        }
    }
    else if (tuilePioche && (unsigned int) event.x < size.y) {
        const unsigned int sizeTuile = size.y / dominoCarre->getHeight();
        size_t x = event.x / sizeTuile;
        size_t y = event.y / sizeTuile;
        if (dominoCarre->placeTile(tuilePioche->getTuile(), x, y)) {
            dominoCarreTuilesGui.at(x).at(y) = tuilePioche;
            dominoCarreTuilesGui.at(x).at(y)->setSize(sizeTuile);
            dominoCarreTuilesGui.at(x).at(y)->setPosition(x * sizeTuile, y * sizeTuile);
            tuilePioche = nullptr;
            for (size_t i = 0; i < joueursGui.size(); i++) {
                joueursGui.at(i).updateValues();
            }
            if (dominoCarre->isFinished()) {
                std::cout << "La partie est finie." << std::endl;
            }
        }
        else {
            std::cout << "La tuile n'est pas jouable à cet emplacement." << std::endl;
        }
    }
    return true;
}

void DominoCarreGUI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (size_t x = 0; x < dominoCarre->getWidth(); x++) {
        for (size_t y = 0; y < dominoCarre->getHeight(); y++) {
            if (dominoCarreTuilesGui[x][y]) {
                target.draw(*dominoCarreTuilesGui[x][y], states);
            }
        }
    }
    target.draw(sacTuilesGui, states);
    if (tuilePioche) {
        target.draw(*tuilePioche, states);
    }
    for (size_t i = 0; i < joueursGui.size(); i++) {
        target.draw(joueursGui.at(i), states);
    }
}