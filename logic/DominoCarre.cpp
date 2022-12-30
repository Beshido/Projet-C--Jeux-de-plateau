#include "DominoCarre.hpp"
#include <random>
#include <vector>

const unsigned int DominoCarre::MIN_VALUE = 100;
const unsigned int DominoCarre::MAX_VALUE = 999;
const unsigned int DominoCarre::SIZE = 8;

DominoCarre::DominoCarre(const size_t size, const size_t amountPlayers): Plateau<DominoCarreTuile> { size, amountPlayers } {
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        DominoCarreTuile* tuile = new DominoCarreTuile { 100, 100, 100, 100 };
        bag.push_back(tuile);
    }
    plateau.at(SIZE / 2).at(SIZE / 2) = drawTile();
}

const bool DominoCarre::isPlayable(const DominoCarreTuile* tuile, const size_t x, const size_t y) const {
    return isAdjacentValuesEqual(tuile, x, y);
}

const bool DominoCarre::isFinished() const {
    return bag.size() == 0;
}

void DominoCarre::updateScore(const size_t x, const size_t y) {
     unsigned int score = 0;
    const std::vector<const DominoCarreTuile*> tuilesAdj = getAdjacentTiles(x, y);
    if (tuilesAdj.at(0)) 
        score += sumDigits(tuilesAdj.at(0)->getValeurNord());
    if (tuilesAdj.at(1)) 
        score += sumDigits(tuilesAdj.at(1)->getValeurOuest());
    if (tuilesAdj.at(2)) 
        score += sumDigits(tuilesAdj.at(2)->getValeurEst());
    if (tuilesAdj.at(3)) 
        score += sumDigits(tuilesAdj.at(3)->getValeurSud());

    players.at(currentPlayer)->concatenateScore(score);
}

const bool DominoCarre::isNextPlayerTurn() const {
    return true;
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

const int DominoCarre::sumDigits(unsigned int n) const {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}