#include "TraxTile.hpp"

TraxTile::TraxTile(const bool flipped): Tile { TraxCouleur::Black, TraxCouleur::White, TraxCouleur::White, TraxCouleur::Black }, flipped { flipped } {}

const bool TraxTile::flip() {
    rotationFactor = 0;
    flipped = !flipped;
    
    if (!flipped) {
        valeurNord = TraxCouleur::Black;
        valeurOuest = TraxCouleur::White;
        valeurEst = TraxCouleur::White;
        valeurSud = TraxCouleur::Black;
    }
    else {
        valeurNord = TraxCouleur::White;
        valeurOuest = TraxCouleur::Black;
        valeurEst = TraxCouleur::White;
        valeurSud = TraxCouleur::Black;
    }
    return flipped;
}

const bool TraxTile::isFlipped() const { return flipped; }