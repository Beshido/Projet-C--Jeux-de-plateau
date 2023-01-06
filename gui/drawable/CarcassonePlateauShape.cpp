#include "CarcassonePlateauShape.hpp"

CarcassonePlateauShape::CarcassonePlateauShape(Carcassone* carcassone): PlateauShape<Carcassone, CarcassoneTileShape, PlayerShape<Joueur<CarcassoneTile>>> { carcassone, sf::Color::Cyan, sf::Color::White } {
    partisansShape = std::vector<std::vector<std::vector<sf::RectangleShape>>> { plateau->getWidth(), std::vector<std::vector<sf::RectangleShape>> { plateau->getHeight(), std::vector<sf::RectangleShape> {} } };
    knightShape = getShapeFromPartisans(Partisan::Knight);
    thiefShape = getShapeFromPartisans(Partisan::Thief);
    peasantShape = getShapeFromPartisans(Partisan::Peasant);
    monkShape = getShapeFromPartisans(Partisan::Monk);
    pass = Bouton { "Passer ", sf::Color::Cyan, sf::Color::White };

}

void CarcassonePlateauShape::setSize(const sf::Vector2u size) {
    PlateauShape<Carcassone, CarcassoneTileShape, PlayerShape<Joueur<CarcassoneTile>>>::setSize(size);
    float partisansSize = tileSize / 4;
    knightShape.setSize(sf::Vector2f { partisansSize, partisansSize });
    knightShape.setPosition(plateau->getWidth() * tileSize, (size.y * 10 / 100 + tileSize) + (4 * (size.y * 10 / 100)) + 50);
    thiefShape.setSize(sf::Vector2f { partisansSize, partisansSize });
    thiefShape.setPosition(plateau->getWidth() * tileSize + 50, (size.y * 10 / 100 + tileSize) + (4 * (size.y * 10 / 100)) + 50);
    peasantShape.setSize(sf::Vector2f { partisansSize, partisansSize });
    peasantShape.setPosition(plateau->getWidth() * tileSize + 100, (size.y * 10 / 100 + tileSize) + (4 * (size.y * 10 / 100)) + 50);
    monkShape.setSize(sf::Vector2f { partisansSize, partisansSize });
    monkShape.setPosition(plateau->getWidth() * tileSize + 150, (size.y * 10 / 100 + tileSize) + (4 * (size.y * 10 / 100)) + 50);
    pass.setSize(size.x * 20 / 100, size.y * 10 / 100);
    pass.setPosition(plateau->getWidth() * tileSize, (size.y * 10 / 100 + tileSize) + (4 * (size.y * 10 / 100)) + 100);
}

void CarcassonePlateauShape::setSize(const unsigned int x, const unsigned int y) {
    setSize( sf::Vector2u { x, y });
}

const bool CarcassonePlateauShape::fireEvent(const sf::Event::MouseButtonEvent event) {
    PlateauShape<Carcassone, CarcassoneTileShape, PlayerShape<Joueur<CarcassoneTile>>>::fireEvent(event);
    if (pass.isClicked(event.x, event.y)) {
        onPassClick(event);
    }
    return true;
}


void CarcassonePlateauShape::onDrawnTileClick(const sf::Event::MouseButtonEvent event) {
    rotateOnDrawnTileClick(event);
}

void CarcassonePlateauShape::onBoardTileClick(const sf::Event::MouseButtonEvent event) {
    placeTileIfPossible(event);
    placePartisanIfPossible(event);
}

void CarcassonePlateauShape::onPassClick(const sf::Event::MouseButtonEvent event) {
    std::cout << "Bouton passer cliqué." << std::endl;
    if (drawnTile) {
        std::cout << "Il faut jouer avant de passer." << std::endl;
        return;
    }
    plateau->nextPlayerTurn();
    nextPlayerShape();
}

void CarcassonePlateauShape::placePartisanIfPossible(const sf::Event::MouseButtonEvent event) {
    if (event.button == sf::Mouse::Right) {
        size_t x = event.x / tileSize;
        size_t y = event.y / tileSize;

        if (plateau->placePartisan(x, y, Partisan::Knight)) {
            partisansShape.at(x).at(y).push_back(getShapeFromPartisans(Partisan::Knight));
            std::cout << "Partisan placé." << std::endl;
        }
    }
}

sf::RectangleShape CarcassonePlateauShape::getShapeFromPartisans(const Partisan partisan) {
    float size = tileSize / 4;
    sf::RectangleShape rectangle { sf::Vector2f { size, size } };
    sf::Color color;
    switch (partisan) {
        case Partisan::Knight:
            color = sf::Color::Red; break;
        case Partisan::Thief:
            color = sf::Color::Black; break;
            break;
        case Partisan::Peasant:
            color = sf::Color::Yellow; break;
            break;
        case Partisan::Monk:
            color = sf::Color::White; break;
            break;
    }
    rectangle.setFillColor(color);
    return rectangle;
}

void CarcassonePlateauShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    PlateauShape::draw(target, states);
    target.draw(knightShape, states);
    target.draw(thiefShape, states);
    target.draw(peasantShape, states);
    target.draw(monkShape, states);
    target.draw(pass, states);
    for (size_t x = 0; x < partisansShape.size(); x++) {
        for (size_t y = 0; y < partisansShape.at(x).size(); y++) {
            for (size_t z = 0; z < partisansShape.at(x).at(y).size(); z++) {
                if (tilesShape[x][y] && tilesShape.at(x).at(y)) {
                    sf::RectangleShape rect { sf::Vector2f{ 20, 20 } };
                    rect.setFillColor(sf::Color::Red);
                    rect.setPosition(x * tileSize, y * tileSize);
                    target.draw(rect, states);
                }
            }
        }
    }
}