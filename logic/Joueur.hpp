#ifndef Joueur_hpp
#define Joueur_hpp

#include "Tile.hpp"
#include <vector>

template <typename P> class Joueur {
    private:
        const std::string nom;
        const unsigned int id;
        unsigned int score;
        std::vector<Tile<P>*> mainJoueur;

    public:
        Joueur(const std::string nom): nom { nom }, id { 0 }, score { 0 } {}
        void ajouterTuile(const Tile<P>* tuile) {
            mainJoueur.push_back(tuile);
        };
        void concatenateScore(const unsigned int score) {
            this->score += score;
        }
        const std::string getName() const {
            return nom;
        }
        const unsigned int getScore() const {
            return score;
        }
};

#endif