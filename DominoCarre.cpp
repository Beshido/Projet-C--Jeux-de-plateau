#include "DominoCarre.hpp"

const unsigned int DominoCarre::MIN_VALUE = 100;
const unsigned int DominoCarre::MAX_VALUE = 999;
const int SIZE = 8;

DominoCarre::DominoCarre(const int unsigned longueur, const unsigned int hauteur, const unsigned int taille): 
    longueur { longueur }, hauteur { hauteur },
    plateau { vector<vector<Tuile<unsigned int>>> { longueur, vector<Tuile<unsigned int>> { hauteur, Tuile<unsigned int> { 100, 100, 100, 100 } } } } {
        srand(time(NULL));
        for (size_t i = 0; i < taille; i++) {
            sacTuiles.push_back(Tuile<unsigned int> { 
                rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE, 
                rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE, 
                rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE, 
                rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE 
            });
        }
        plateau.at(longueur / 2).at(hauteur / 2) = piocherTuile();
}
//generate a playable set of DominoCarre


const Tuile<unsigned int> DominoCarre::piocherTuile() {
    int random = rand() % sacTuiles.size();
    Tuile<unsigned int> tuile = sacTuiles.at(random);
    sacTuiles.erase(sacTuiles.begin() + random);
    return tuile;
}

/*void DominoCarre::placerTuile(int x, int y, Tuile<unsigned int> tuile , vector<vector<Tuile<unsigned int>>> plateau){
    if(x < 0 || y < 0 || x > this->plateau.size() || y > this->plateau.size() || this->plateau[x][y] != NULL || 
    (x > 0 && this->plateau[x-1][y].getValeurEst() != tuile.getValeurOuest()) || 
    x > 0 && this->plateau[x-1][y].getValeurNord() != tuile.getValeurSud()    || 
    x > 0 && this ->plateau[x-1][y].getValeurSud() != tuile.getValeurNord()   ||
    x > 0 && this->plateau[x-1][y].getValeurOuest() != tuile.getValeurEst()){
        cout << "La tuile ne peut pas être placée à ces coordonnées" << endl;
    }
    else{
        this->plateau[x][y] = tuile;
    }

}*/
void DominoCarre::placerTuile(int i, int j, Tuile<unsigned int> tuile , vector<vector<Tuile<unsigned int>>> plateau){
if (i > 0) {
    if (this->plateau [i][j].getValeurNord() != this->plateau[i-1][j].getValeurSud()) {
      return;
    }
  }
  if (i < SIZE - 1) {
    if (this->plateau[i][j].getValeurSud() != this->plateau[i+1][j].getValeurNord()) {
      return;
    }
  }
  if (j > 0) {
    if (this->plateau[i][j].getValeurOuest() != this->plateau[i][j-1].getValeurEst()) {
      return;
    }
  }
  if (j < SIZE - 1) {
    if (this->plateau[i][j].getValeurEst() != this->plateau[i][j+1].getValeurOuest()) {
      return;
    }
  }

  this->plateau[i][j] = tuile;
}


const unsigned int DominoCarre::getLongueur() const {
    return longueur;
}

const unsigned int DominoCarre::getHauteur() const {
    return hauteur;
}

const vector<vector<Tuile<unsigned int>>> DominoCarre::getPlateau() const {
    return plateau;
}