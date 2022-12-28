#include "DominoCarre.hpp"
#include <random>
#include <vector>

const unsigned int DominoCarre::MIN_VALUE = 100;
const unsigned int DominoCarre::MAX_VALUE = 999;
const unsigned int DominoCarre::SIZE = 8;

DominoCarre::DominoCarre(const size_t taille, const size_t nombreJoueurs) {
    plateau = std::vector<std::vector<DominoCarreTuile*>> { SIZE, std::vector<DominoCarreTuile*> { SIZE, nullptr } };
    srand(time(NULL));
    for (size_t i = 0; i < taille; i++) {
        DominoCarreTuile* tuile = new DominoCarreTuile { 100, 100, 100, 100 };
        bag.push_back(tuile);
    }
    plateau.at(SIZE / 2).at(SIZE / 2) = drawTile();
    for (unsigned int i = 0; i < nombreJoueurs; i++) {
        std::string playerName = "Joueur ";
        playerName.append(std::to_string(i + 1));
        players.push_back(new Joueur<DominoCarreTuile> { playerName });
    }
    currentPlayer = 0;
}

const bool DominoCarre::isFinished() const {
    return bag.size() == 0;
}

void DominoCarre::updateScore(const size_t x, const size_t y) {
     unsigned int score = 0;
    const std::vector<const DominoCarreTuile*> tuilesAdj = getAdjacentTiles(x, y);
    if (tuilesAdj.at(0)) 
        score += tuilesAdj.at(0)->getValeurNord();
    if (tuilesAdj.at(1)) 
        score += tuilesAdj.at(1)->getValeurOuest();
    if (tuilesAdj.at(2)) 
        score += tuilesAdj.at(2)->getValeurEst();
    if (tuilesAdj.at(3)) 
        score += tuilesAdj.at(3)->getValeurSud();

    players.at(currentPlayer)->concatenateScore(score);
}

void DominoCarre::nextPlayer() {
    currentPlayer = currentPlayer >= players.size() - 1 ? 0 : currentPlayer + 1;
}

const Joueur<DominoCarreTuile>* DominoCarre::getWinner() const {
    Joueur<DominoCarreTuile>* winner = players.at(0);
    for (size_t i = 1; i < players.size(); i++) {
        if (players.at(i)->getScore() > winner->getScore()) {
            winner = players.at(i);
        }
    }
    return winner;
}