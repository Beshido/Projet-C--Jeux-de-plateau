#ifndef Joueur_hpp
#define Joueur_hpp

#include "Tuile.hpp"
#include <vector>

template <typename T> class Joueur {
    private:
        const std::string nom;
        const unsigned int id;
        unsigned int score;
        std::vector<Tuile<T>*> mainJoueur;

    public:
        Joueur(const std::string nom): nom { nom }, id { 0 }, score { 0 } {}
        void ajouterTuile(const Tuile<T>* tuile) {
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