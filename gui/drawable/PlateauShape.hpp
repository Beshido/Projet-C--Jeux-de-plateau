#ifndef _PlateauShape
#define _PlateauShape

#include "Bouton.hpp"
#include "../Assets.hpp"
#include "../../logic/Joueur.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

template <typename P, typename TileShape, typename PlayerShape> class PlateauShape: public sf::Drawable, public sf::Transformable {
    public:
        PlateauShape(P* plateau): plateau { plateau }, tilesShape { std::vector<std::vector<TileShape*>>{} } , drawButton { Bouton { "Piocher" } } {
            for (size_t x = 0; x < plateau->getWidth(); x++) {
                tilesShape.push_back(std::vector<TileShape*>{});
                for (size_t y = 0; y < plateau->getHeight(); y++) {
                    TileShape* tilePtr = nullptr;
                    if (plateau->getPlateau().at(x).at(y)) {
                        tilePtr = new TileShape { plateau->getPlateau().at(x).at(y) };
                        tilePtr->setPosition(x * tilePtr->getSize().x, y * tilePtr->getSize().y);
                    }
                    tilesShape.at(x).push_back(tilePtr);
                }
            }
            drawnTile = nullptr;
            for (size_t i = 0; i < plateau->getPlayers().size(); i++) {
                playersShape.push_back(PlayerShape { plateau->getPlayers().at(i) });
            }
            playersShape.at(plateau->getCurrentPlayerIndex()).active();
        }

        const sf::Vector2u getSize() const {
            return size;
        }

        void setSize(const sf::Vector2u size) {
            tileSize = size.y / plateau->getHeight();
            for (size_t i = 0; i < plateau->getWidth(); i++) {
                for (size_t j = 0; j < plateau->getHeight(); j++) {
                    if (!tilesShape.at(i).at(j))
                        continue;
                    tilesShape.at(i).at(j)->setSize(tileSize);
                    tilesShape.at(i).at(j)->setPosition(i * tileSize, j * tileSize);
                }
            }
            drawButton.setSize(size.x * 20 / 100, size.y * 10 / 100);
            drawButton.setPosition(plateau->getWidth() * tileSize, 0);
            if (drawnTile) {
                drawnTile->setSize(tileSize);
                drawnTile->setPosition(plateau->getWidth() * tileSize, size.y * 10 / 100);
            }
            for (size_t i = 0; i < playersShape.size(); i++) {
                playersShape.at(i).setSize(size.x * 20 / 100, size.y * 10 / 100);
                playersShape.at(i).setPosition(plateau->getWidth() * tileSize, (size.y * 10 / 100 + tileSize) * (i + 1));
            }

            this->size = size;
        }

        void setSize(const unsigned int x, const unsigned int y) {
            setSize(sf::Vector2u { x, y });
        }

        const bool fireEvent(const sf::Event::MouseButtonEvent event) {
            if (drawButton.isClicked(event.x, event.y)) {
                onDrawClick();
            }
            else if (drawnTile && drawnTile->isClicked(event.x, event.y)) {
                onDrawnTileClick(event);
                
            }
            else if (drawnTile && (unsigned int) event.x < size.y) {
                size_t x = event.x / tileSize;
                size_t y = event.y / tileSize;
                if (plateau->placeTile(drawnTile->getTile(), x, y)) {
                    tilesShape.at(x).at(y) = drawnTile;
                    tilesShape.at(x).at(y)->setSize(tileSize);
                    tilesShape.at(x).at(y)->setPosition(x * tileSize, y * tileSize);
                    drawnTile = nullptr;
                    for (size_t i = 0; i < playersShape.size(); i++) {
                        playersShape.at(i).inactive();
                        playersShape.at(i).update();
                    }
                    if (plateau->isFinished()) {
                        std::cout << "La partie est finie." << std::endl;
                    }
                    playersShape.at(plateau->getCurrentPlayerIndex()).active();

                }
                else {
                    std::cout << "La tuile n'est pas jouable à cet emplacement." << std::endl;
                }
            }
            return true;
        }

        void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            states.transform *= getTransform();
            for (size_t x = 0; x < plateau->getWidth(); x++) {
                for (size_t y = 0; y < plateau->getHeight(); y++) {
                    if (tilesShape[x][y]) {
                        target.draw(*tilesShape.at(x).at(y), states);
                    }
                }
            }
            target.draw(drawButton, states);
            if (drawnTile) {
                target.draw(*drawnTile, states);
            }
            for (size_t i = 0; i < playersShape.size(); i++) {
                target.draw(playersShape.at(i), states);
            }
        }

    protected:
        P* plateau;

        std::vector<std::vector<TileShape*>> tilesShape;
        std::vector<PlayerShape> playersShape;
        Bouton drawButton;
        TileShape* drawnTile;

        sf::Vector2u size;
        unsigned int tileSize;

        const bool onDrawClick() {
            std::cout << "Bouton sac de tuile cliqué." << std::endl;
            drawnTile = new TileShape { plateau->drawTile() };

            drawnTile->setSize(tileSize);
            drawnTile->centerOrigin();
            drawnTile->setPosition(plateau->getWidth() * tileSize, size.y * 10 / 100);
            return true;
        }

        void rotateOnDrawnTileClick(const sf::Event::MouseButtonEvent event) {
            switch (event.button) {
                case sf::Mouse::Left:
                    std::cout << "Rotation gauche." << std::endl;
                    drawnTile->getTile()->tournerGauche();
                    drawnTile->update();
                    break;
                case sf::Mouse::Right:
                    std::cout << "Rotaiton droite." << std::endl;
                    drawnTile->getTile()->tournerDroite();
                    drawnTile->update();
                    break;
                default:
                    break;
            }
        }

        virtual void onDrawnTileClick(const sf::Event::MouseButtonEvent event) = 0;
};

#endif
