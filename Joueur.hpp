#ifndef Joueur_hpp
#define Joueur_hpp

#include "Tuile.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>

template <typename T> class Joueur {
    private:
        const std::string nom;
        const int id;
        int score;
        std::vector<Tuile<T>*> mainJoueur;

    public:
        Joueur(const std::string nom): nom { nom }, id { 0 }, score { 0 } {}
        void ajouterTuile(const Tuile<T>* tuile) {
            mainJoueur.push_back(tuile);
        };
};

#endif