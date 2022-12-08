#include "Joueur.hpp"

using namespace std;

Joueur::Joueur(string nom){
    this->nom = nom;
    this->id = id++;
    this->score = 0;
}

void Joueur::ajouterTuile(Tuile tuile){
    this->mainJoueur.push_back(tuile);
}

