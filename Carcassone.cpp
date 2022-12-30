#include "Carcassone.hpp"
#include "CarcassoneTuile.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Tuile.hpp"
#include <random>
#include <vector>

const unsigned int Carcassone::SIZE = 8;
const unsigned int Carcassone::MIN_VALUE = 0;

Carcassone::Carcassone(const size_t taille, const size_t nombreJoueurs) {
    plateau = std::vector<std::vector<CarcassoneTuile*>> { SIZE, std::vector<CarcassoneTuile*> { SIZE, nullptr } };
    srand(time(NULL));
    for (size_t i = 0; i < taille; i++) {
        CarcassoneTuile* tuile = new CarcassoneTuile { CarcassoneType::Grassland };
        bag.push_back(tuile);
    }
    plateau.at(SIZE / 2).at(SIZE / 2) = drawTile();
    for (unsigned int i = 0; i < nombreJoueurs; i++) {
        std::string playerName = "Joueur ";
        playerName.append(std::to_string(i + 1));
        players.push_back(new Joueur<CarcassoneTuile> { playerName });
    }
    currentPlayer = 0;
}
const bool Carcassone::isFinished() const {
    return last_tile_placed_ || remaining_tiles_ == 0;
}
void Carcassone::isNextPlayerTurn() {
    currentPlayer = currentPlayer >= players.size() - 1 ? 0 : currentPlayer + 1;
}
Joueur* DetermineWinner() {
    Joueur* winner = nullptr;
    int highest_score = INT_MIN;  // Initialize to lowest possible value
    for (const auto& player : players_) {
      if (Joueur->GetScore() > highest_score) {
        winner = player;
        highest_score = player->GetScore();
      }
    }
    return winner;
  }

