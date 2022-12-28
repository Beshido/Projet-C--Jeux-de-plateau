#include "Trax.hpp"

Trax::Trax() {
    bag = std::vector<TraxTile*> { 64, new TraxTile {} };
    plateau = std::vector<std::vector<TraxTile*>> { 8, std::vector<TraxTile*> { 8, nullptr } };

}

const bool Trax::isFinished() const {
    return false;
}

void Trax::nextPlayer() {

}
    
const Joueur<TraxTile>* Trax::getWinner() const {
    return nullptr;
}