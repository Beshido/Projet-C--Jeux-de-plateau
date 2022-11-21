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
