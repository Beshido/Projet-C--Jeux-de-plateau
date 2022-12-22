#ifndef Joueur_hpp
#define Joueur_hpp

#include "Tuile.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Joueur{
    private:
        vector<Tuile<unsigned int>> mainJoueur;
        int score;
        string nom;
        int id;

    public:
        Joueur(string nom);
        void ajouterTuile(Tuile<unsigned int> tuile);
        void afficherScore();
        void afficherNom();
        void afficherId();
        void sauvegarderPartie();
        void afficherAide();
        void afficherRegles();
        void quitter();
};

#endif