#ifndef _Plateau
#define _Plateau

#include "Joueur.hpp"
#include <stdexcept>
#include <vector>

template <typename T> class Plateau {
    public:
        T* drawTile() {
            if (bag.size() < 0) 
                return nullptr;

            size_t random = rand() % bag.size();
            T* tuile = bag.at(random);
            bag.erase(bag.begin() + random);
            return tuile;
        }

        const bool placeTile(T* tuile, const size_t x, const size_t y) {
            if (isPlayable(tuile, x, y)) {
                unsigned int score = 0;
                const std::vector<const T*> tuilesAdj = getAdjacentTiles(x, y);
                if (tuilesAdj.at(0)) 
                    score += tuilesAdj.at(0)->getValeurNord();
                if (tuilesAdj.at(1)) 
                    score += tuilesAdj.at(1)->getValeurOuest();
                if (tuilesAdj.at(2)) 
                    score += tuilesAdj.at(2)->getValeurEst();
                if (tuilesAdj.at(3)) 
                    score += tuilesAdj.at(3)->getValeurSud();

                players.at(currentPlayer)->concatenateScore(score);
                nextPlayer();

                plateau.at(x).at(y) = tuile;
                return true;
            }
            return false;
        }

        const bool isPlayable(const T* tile) const {
            for (size_t i = 0; i < plateau.size(); i++) {
                for (size_t j = 0; j < plateau.at(i).size(); j++) {
                    if (plateau.at(i).at(j)) {
                        bool isPlayable = 
                            (j > 0 && plateau.at(i).at(j - 1) == nullptr && plateau.at(i).at(j)->getValeurNord() == tile->getValeurNord()) ||
                            (i > 0 && plateau.at(i - 1).at(j) == nullptr && plateau.at(i).at(j)->getValeurOuest() == tile->getValeurOuest()) ||
                            (i < plateau.size() - 1 && plateau.at(i + 1).at(j) == nullptr && plateau.at(i).at(j)->getValeurEst() == tile->getValeurEst()) ||
                            (j < plateau.at(i).size() - 1 && plateau.at(i).at(j + 1) == nullptr && plateau.at(i).at(j)->getValeurSud() == tile->getValeurSud());
                        if (isPlayable) 
                            return isPlayable;
                    }
                }
            }
            return false;
        }
        
        const size_t getWidth() const { return plateau.size(); }
        const size_t getHeight() const { try { return plateau.at(0).size(); } catch (const std::out_of_range& e) { return 0; } }
        const std::vector<std::vector<T*>> getPlateau() const { return plateau; }
        const std::vector<Joueur<T>*> getPlayers() const { return players; }

        virtual void nextPlayer() = 0;
        virtual const Joueur<T>* getWinner() const = 0;


    protected:
        std::vector<std::vector<T*>> plateau;
        std::vector<T*> bag;
        std::vector<Joueur<T>*> players;
        size_t currentPlayer;

        const bool isPlayable(const T* tuile, const size_t x, const size_t y) const {
            if (plateau.at(x).at(y)) return false;

            const std::vector<const T*> tuilesAdj = getAdjacentTiles(x, y);
            if (tuilesAdj == std::vector<const T*> { 4, nullptr }) {
                return false;
            }

            return !plateau.at(x).at(y) &&
                ((tuilesAdj.at(0) && tuilesAdj.at(0)->getValeurNord() == tuile->getValeurNord()) || !tuilesAdj.at(0)) &&
                ((tuilesAdj.at(1) && tuilesAdj.at(1)->getValeurOuest() == tuile->getValeurOuest()) || !tuilesAdj.at(1)) &&
                ((tuilesAdj.at(2) && tuilesAdj.at(2)->getValeurEst() == tuile->getValeurEst()) || !tuilesAdj.at(2)) &&
                ((tuilesAdj.at(3) && tuilesAdj.at(3)->getValeurSud() == tuile->getValeurSud()) || !tuilesAdj.at(3));
        }

        const std::vector<const T*> getAdjacentTiles(const size_t x, const size_t y) const {
            std::vector<const T*> adjacentTiles { 4, nullptr };
            if (y > 0) adjacentTiles.at(0) = plateau.at(x).at(y - 1);
            if (x > 0) adjacentTiles.at(1) = plateau.at(x - 1).at(y);
            if (x < plateau.size() - 1) adjacentTiles.at(2) = plateau.at(x + 1).at(y);
            if (y < plateau.at(x).size() - 1) adjacentTiles.at(3) = plateau.at(x).at(y + 1);
            return adjacentTiles;
        }
};

#endif