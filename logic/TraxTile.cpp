#include "TraxTile.hpp"

TraxTile::TraxTile(): Tile { TraxCouleur::Black, TraxCouleur::White, TraxCouleur::White, TraxCouleur::Black } {}

void TraxTile::flip() {
    rotationFactor = 0;

    if (!flipped) {
        valeurNord = TraxCouleur::White;
        valeurOuest = TraxCouleur::Black;
        valeurEst = TraxCouleur::White;
        valeurSud = TraxCouleur::Black;
    }
    else {
        valeurNord = TraxCouleur::Black;
        valeurOuest = TraxCouleur::White;
        valeurEst = TraxCouleur::White;
        valeurSud = TraxCouleur::Black;
    }

    flipped = !flipped;
}