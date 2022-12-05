#ifndef Joueur_hpp
#define Joueur_hpp

#include <stdio.h>
#include <vector>

#include <iostream>
using namespace std;

class Joueur{
private:
    vector<Tuile> mainJoueur;
    int score;
    string nom;
    int id;

public:
    Joueur(string nom);
    void ajouterTuile(Tuile tuile);
    void afficherScore();
    void afficherNom();
    void afficherId();
    void sauvegarderPartie();
    void afficherAide();
    void afficherRegles();
    void quitter();
};

#endif