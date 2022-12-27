#include "DominoCarre.hpp"

const unsigned int DominoCarre::MIN_VALUE = 100;
const unsigned int DominoCarre::MAX_VALUE = 999;
const unsigned int DominoCarre::SIZE = 8;

DominoCarre::DominoCarre(const size_t taille, const size_t nombreJoueurs) {
    plateau = std::vector<std::vector<DominoCarreTuile*>> { SIZE, std::vector<DominoCarreTuile*> { SIZE, nullptr } };
    std::cout << "ab" << std::endl;
    srand(time(NULL));
    std::cout << "ab" << std::endl;
    for (size_t i = 0; i < taille; i++) {
        DominoCarreTuile* tuile = new DominoCarreTuile { 100, 100, 100, 100 };
        bag.push_back(tuile);
    }
    std::cout << "ab" << std::endl;
    plateau.at(SIZE / 2).at(SIZE / 2) = drawTile();
    std::cout << "ab" << std::endl;
    for (unsigned int i = 0; i < nombreJoueurs; i++) {
        std::string playerName = "Joueur ";
        playerName.append(std::to_string(i + 1));
        players.push_back(new Joueur<DominoCarreTuile> { playerName });
    }
    std::cout << "ab" << std::endl;
    currentPlayer = 0;
}

const bool DominoCarre::isFinished() const {
    return bag.size() == 0;
}

/* const Joueur<DominoCarreTuile>* DominoCarre::getWinner() const {
    Joueur<DominoCarreTuile>* winner = players.at(0);
    for (size_t i = 1; i < players.size(); i++) {
        if (players.at(i)->getScore() > winner->getScore()) {
            winner = players.at(i);
        }
    }
    return winner;
} */