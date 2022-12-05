#include "DominoCarre.hpp"
#include <vector>
#include "Tuile.hpp"
#include <random>

#include <iostream>
using namespace std;

DominoCarre::DominoCarre(vector <Tuile> sacTuiles){
    this->sacTuiles = sacTuiles;
}

Tuile DominoCarre::piocherTuile(){
    int random = rand() % this->sacTuiles.size();
    this->sacTuiles.erase(this->sacTuiles.begin() + random);
    return this->sacTuiles[random];      
}
void DominoCarre::placerTuile(int x, int y, Tuile tuile , vector<vector<Tuile>> plateau){
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

}