#ifndef _Plateau
#define _Plateau

#include "Joueur.hpp"
#include <stdexcept>
#include <vector>

template <typename P> class Plateau {
    public:
        P* drawTile() {
            if (bag.size() < 0) 
                return nullptr;

            size_t random = rand() % bag.size();
            P* tuile = bag.at(random);
            bag.erase(bag.begin() + random);
            return tuile;
        }

        const bool placeTile(P* tuile, const size_t x, const size_t y) {
            if (isPlayable(tuile, x, y)) {
                plateau.at(x).at(y) = tuile;
                nextPlayer();
                updateScore(x, y);
                return true;
            }
            return false;
        }

        const bool isPlayable(const P* tile) const {
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
        const size_t getHeight() const { try { return plateau.at(0).size(); } catch (const std::out_of_range& e) { return 0; } catch (...) { return 0; } }
        std::vector<std::vector<P*>> getPlateau() const { return plateau; }
        const std::vector<Joueur<P>*> getPlayers() const { return players; }

        virtual void nextPlayer() = 0;
        virtual void updateScore(const size_t x, const size_t y) = 0;
        virtual const Joueur<P>* getWinner() const = 0;
        virtual const bool isFinished() const = 0;

    protected:
        std::vector<std::vector<P*>> plateau;
        std::vector<P*> bag;
        std::vector<Joueur<P>*> players;
        size_t currentPlayer;

        const bool isPlayable(const P* tuile, const size_t x, const size_t y) const {
            if (plateau.at(x).at(y)) return false;

            const std::vector<const P*> tuilesAdj = getAdjacentTiles(x, y);
            if (tuilesAdj == std::vector<const P*> { 4, nullptr }) {
                return false;
            }

            return !plateau.at(x).at(y) &&
                ((tuilesAdj.at(0) && tuilesAdj.at(0)->getValeurNord() == tuile->getValeurNord()) || !tuilesAdj.at(0)) &&
                ((tuilesAdj.at(1) && tuilesAdj.at(1)->getValeurOuest() == tuile->getValeurOuest()) || !tuilesAdj.at(1)) &&
                ((tuilesAdj.at(2) && tuilesAdj.at(2)->getValeurEst() == tuile->getValeurEst()) || !tuilesAdj.at(2)) &&
                ((tuilesAdj.at(3) && tuilesAdj.at(3)->getValeurSud() == tuile->getValeurSud()) || !tuilesAdj.at(3));
        }

        const std::vector<const P*> getAdjacentTiles(const size_t x, const size_t y) const {
            std::vector<const P*> adjacentTiles { 4, nullptr };
            if (y > 0) adjacentTiles.at(0) = plateau.at(x).at(y - 1);
            if (x > 0) adjacentTiles.at(1) = plateau.at(x - 1).at(y);
            if (x < plateau.size() - 1) adjacentTiles.at(2) = plateau.at(x + 1).at(y);
            if (y < plateau.at(x).size() - 1) adjacentTiles.at(3) = plateau.at(x).at(y + 1);
            return adjacentTiles;
        }
};

#endif