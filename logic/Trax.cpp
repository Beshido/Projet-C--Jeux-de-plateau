#include "Trax.hpp"
#include "TraxTuile.hpp"
#include "Tuile.hpp"
#include "Joueur.hpp"

#include <iostream>

Trax::Trax(const size_t taille, const size_t nombreJoueurs) {
    plateau = std::vector<std::vector<TraxTuile*>> { SIZE, std::vector<TraxTuile*> { SIZE, nullptr } };
    srand(time(NULL));
    for (size_t i = 0; i < taille; i++) {
        TraxTuile* tuile = new TraxTuile { 100, 100, 100, 100 };
        bag.push_back(tuile);
    }
    plateau.at(SIZE / 2).at(SIZE / 2) = drawTile();
    for (unsigned int i = 0; i < nombreJoueurs; i++) {
        std::string playerName = "Joueur ";
        playerName.append(std::to_string(i + 1));
        players.push_back(new Joueur<TraxTuile> { playerName });
    }
    currentPlayer = 0;
}

//Implement the forced play rule of Trax here
void Trax::forcedPlay() {
    for (size_t i = 0; i < players.size(); i++) {
        Joueur<TraxTuile>* player = players.at(i);
        for (size_t j = 0; j < player->getHand().size(); j++) {
            TraxTuile* tile = player->getHand().at(j);
            //If the tile is not surrounded, skip it
            if (tile->IsSurrounded()) {
                continue;
            }
            //If the tile is surrounded, play it
            if (playTile(tile, i)) {
                player->removeTile(tile);
            }
        }
    }
}

