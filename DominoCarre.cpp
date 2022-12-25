#include "DominoCarre.hpp"

const unsigned int DominoCarre::MIN_VALUE = 100;
const unsigned int DominoCarre::MAX_VALUE = 999;
const unsigned int DominoCarre::SIZE = 8;

DominoCarre::DominoCarre(const unsigned int taille, const unsigned int nombreJoueurs): plateau { std::vector<std::vector<Tuile<unsigned int>*>> { SIZE, std::vector<Tuile<unsigned int>*> { SIZE, nullptr } } } {
    srand(time(NULL));
    for (size_t i = 0; i < taille; i++) {
        Tuile<unsigned int>* tuile = new Tuile<unsigned int> { 
            rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE, 
            rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE, 
            rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE, 
            rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE 
        };
        sacTuiles.push_back(tuile);
    }
    plateau.at(SIZE / 2).at(SIZE / 2) = piocherTuile();
    for (unsigned int i = 0; i < nombreJoueurs; i++) {
        std::string playerName = "Joueur ";
        playerName.append(std::to_string(i));
        joueurs.push_back(new Joueur<unsigned int> { playerName });
    }
}

Tuile<unsigned int>* DominoCarre::piocherTuile() {
    size_t random = rand() % sacTuiles.size();
    Tuile<unsigned int>* tuile = sacTuiles.at(random);
    sacTuiles.erase(sacTuiles.begin() + random);
    return tuile;
}

const bool DominoCarre::placerTuile(Tuile<unsigned int>* tuile, const size_t x, const size_t y) {
    if (isPlayable(tuile, x, y)) {
        plateau.at(x).at(y) = tuile;
        return true;
    }
    return false;
}

const bool DominoCarre::isPlayable(const Tuile<unsigned int>* tuile, const size_t x, const size_t y) const {
    return true;/* plateau.at(x).at(y) == nullptr &&
        ((y > 0 && plateau.at(x).at(y - 1) && plateau.at(x).at(y - 1)->getValeurNord() == tuile->getValeurNord()) ||
        (x > 0 && plateau.at(x - 1).at(y) && plateau.at(x - 1).at(y)->getValeurOuest() == tuile->getValeurOuest()) ||
        (x < plateau.size() - 1 && plateau.at(x + 1).at(y) && plateau.at(x + 1).at(y)->getValeurEst() == tuile->getValeurEst()) ||
        (y < plateau.at(x).size() - 1 && plateau.at(x).at(y + 1) && plateau.at(x).at(y + 1)->getValeurSud() == tuile->getValeurSud())); */
}

const bool DominoCarre::isPlayable(const Tuile<unsigned int>* tuile) const {
    for (size_t i = 0; i < plateau.size(); i++) {
        for (size_t j = 0; j < plateau.at(i).size(); j++) {
            if (plateau.at(i).at(j) != nullptr) {
                bool isPlayable = 
                    (j > 0 && plateau.at(i).at(j - 1) == nullptr && plateau.at(i).at(j)->getValeurNord() == tuile->getValeurNord()) ||
                    (i > 0 && plateau.at(i - 1).at(j) == nullptr && plateau.at(i).at(j)->getValeurOuest() == tuile->getValeurOuest()) ||
                    (i < plateau.size() - 1 && plateau.at(i + 1).at(j) == nullptr && plateau.at(i).at(j)->getValeurEst() == tuile->getValeurEst()) ||
                    (j < plateau.at(i).size() - 1 && plateau.at(i).at(j + 1) == nullptr && plateau.at(i).at(j)->getValeurSud() == tuile->getValeurSud());
                if (isPlayable) 
                    return isPlayable;
            }
        }
    }
    return false;
}

const unsigned int DominoCarre::getLongueur() const {
    return SIZE;
}

const unsigned int DominoCarre::getHauteur() const {
    return SIZE;
}

const std::vector<std::vector<Tuile<unsigned int>*>> DominoCarre::getPlateau() const {
    return plateau;
}