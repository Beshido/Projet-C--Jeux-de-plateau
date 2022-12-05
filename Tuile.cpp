#include "Tuile.hpp"
#include <iostream>
#include <array>

using namespace std;

Tuile::Tuile(int valeurNord, int valeurSud, int valeurEst, int valeurOuest){
    this->valeurNord = valeurNord;
    this->valeurSud = valeurSud;
    this->valeurEst = valeurEst;
    this->valeurOuest = valeurOuest;
}
int Tuile::getValeurNord(){
    return this->valeurNord;
}
int Tuile::getValeurSud(){
    return this->valeurSud;
}
int Tuile::getValeurEst(){
    return this->valeurEst;
}
int Tuile::getValeurOuest(){
    return this->valeurOuest;
}
array<int,3> intToArray(int valeur){
    array<int,3> array;
    for (int i = 2; i >= 0; i--) {
    if(valeur > 0){
        array[i] = valeur % 10;
        valeur /= 10;
    }
    else{
        array[i] = 0;
    }
}
return array;
}

void Tuile::TournerGauche(){
    int temp = this->valeurNord;
    this->valeurNord = this->valeurOuest;
    this->valeurOuest = this->valeurSud;
    this->valeurSud = this->valeurEst;
    this->valeurEst = temp;
}
void Tuile::TournerDroite(){
    int temp = this->valeurNord;
    this->valeurNord = this->valeurEst;
    this->valeurEst = this->valeurSud;
    this->valeurSud = this->valeurOuest;
    this->valeurOuest = temp;
}

    
