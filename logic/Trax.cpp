#include "Trax.hpp"

Trax::Trax(): Plateau<TraxTile> { 8, 2 } {
    bag = std::vector<TraxTile*> {};
    for (size_t i = 0; i < 64; i++) {
        bag.push_back(new TraxTile {});
    }
    plateau = std::vector<std::vector<TraxTile*>> { 8, std::vector<TraxTile*> { 8, nullptr } };
    firstPlay = true;
}

const bool Trax::isPlayable(const TraxTile* tuile, const size_t x, const size_t y) const {
    if (isForcedMoveAvailable()) {
        isForcedMove(x, y) && isAdjacentValuesEqual(tuile, x, y);
    }
    return isAdjacentValuesEqual(tuile, x, y) || firstPlay;
}

const bool Trax::isFinished() const {
    for (size_t x = 0; x < getWidth(); x++) {
        for (size_t y = 0; y < getHeight(); y++) {
            if (isFinishedRecursive(TraxCouleur::Black, x, y, plateau.at(x).at(y), x, y, true)) {
                players.at(0)->concatenateScore(1);
                return true;
            }
            else if (isFinishedRecursive(TraxCouleur::White, x, y, plateau.at(x).at(y), x, y, true)) {
                players.at(1)->concatenateScore(1);
                return true;
            }
        }
    }
    return false;
}

const bool Trax::isFinishedRecursive(const TraxCouleur color, const size_t sourceX, const size_t sourceY, const TraxTile* previousTile, const size_t x, const size_t y, const bool first) const {
    if (!plateau.at(x).at(y)) {
        return false;
    }

    if ((!first && (sourceX == x && sourceY == y)) || ((sourceX == 0 && x == getWidth() - 1) || (sourceX == getWidth() - 1 && x == 0) || (sourceY == 0 && y == getHeight() - 1) || (sourceY == getHeight() - 1 && y == 0))) {
        return true;
    }

    const std::vector<const TraxTile*> adjacentTiles = getAdjacentTiles(x, y);
    if (adjacentTiles.at(0) && adjacentTiles.at(0)->getValeurSud() == color && adjacentTiles.at(0) != previousTile) {
        return isFinishedRecursive(color, sourceX, sourceY, plateau.at(x).at(y), x, y - 1);
    }
    else if (adjacentTiles.at(1) && adjacentTiles.at(1)->getValeurEst() == color && adjacentTiles.at(1) != previousTile) {
        return isFinishedRecursive(color, sourceX, sourceY, plateau.at(x).at(y), x - 1, y);
    }
    else if (adjacentTiles.at(2) && adjacentTiles.at(2)->getValeurOuest() == color && adjacentTiles.at(2) != previousTile) {
        return isFinishedRecursive(color, sourceX, sourceY, plateau.at(x).at(y), x + 1, y);
    }
    else if (adjacentTiles.at(3) && adjacentTiles.at(3)->getValeurNord() == color && adjacentTiles.at(3) != previousTile) {
        return isFinishedRecursive(color, sourceX, sourceY, plateau.at(x).at(y), x, y + 1);
    }

    return false;
}

const bool Trax::isNextPlayerTurn() const {
    return !isForcedMoveAvailable();
}

void Trax::updateScore(const size_t x, const size_t y) {
    firstPlay = false;
}
    
const Joueur<TraxTile>* Trax::getWinner() const {
    return nullptr;
}

const bool Trax::isForcedMoveAvailable() const {
    for (size_t x = 0; x < getWidth(); x++) { // vérification si un coup forcé est possible. si oui, le joueur actuel continue de jouer.
        for (size_t y = 0; y < getHeight(); y++) {
            if (isForcedMove(x, y)) return true;
        }
    }
    return false;
}

const bool Trax::isForcedMove(const size_t x, const size_t y) const {
    if (plateau.at(x).at(y)) return false;

    const std::vector<const TraxTile*> adjacentTiles = getAdjacentTiles(x, y);
    std::vector<TraxCouleur> adjacentTilesValues {};
    if (adjacentTiles.at(0)) adjacentTilesValues.push_back(adjacentTiles.at(0)->getValeurNord());
    if (adjacentTiles.at(1)) adjacentTilesValues.push_back(adjacentTiles.at(1)->getValeurOuest());
    if (adjacentTiles.at(2)) adjacentTilesValues.push_back(adjacentTiles.at(2)->getValeurEst());
    if (adjacentTiles.at(3)) adjacentTilesValues.push_back(adjacentTiles.at(3)->getValeurSud());

    if (adjacentTilesValues.size() < 2) return false;

    for (size_t i = 0; i < adjacentTilesValues.size() - 1; i++) {
        for (size_t j = i + 1; j < adjacentTilesValues.size(); j++) {
            if (adjacentTilesValues.at(i) == adjacentTilesValues.at(j)) return true;
        }
    }
    return false;
}