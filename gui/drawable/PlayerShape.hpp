#ifndef _PlayerShape
#define _PlayerShape

#include "../Assets.hpp"
#include "../../logic/Joueur.hpp"
#include <SFML/Graphics.hpp>

template <typename Player> class PlayerShape: public sf::Drawable, public sf::Transformable {
    public:
        PlayerShape(Player* player): player { player } {
            rectangle.setFillColor(sf::Color::White);
            rectangle.setOutlineThickness(3);

            name.setFont(Assets::font);
            name.setFillColor(sf::Color::Black);
            name.setString(player->getName());
            score.setFont(Assets::font);
            score.setFillColor(sf::Color::Black);

            update();
        }
        
        ~PlayerShape() {
            std::cout << "PlayerShape supprimé." << std::endl;
        }

        void active() {
            rectangle.setOutlineColor(sf::Color::Red);
        }

        void inactive() {
            rectangle.setOutlineColor(sf::Color::Black);
        }

        void setSize(const float x, const float y) {
            rectangle.setSize(sf::Vector2f { x, y });
            name.setCharacterSize(y / 2);
            score.setCharacterSize(y / 2);
            score.setPosition(0, name.getLocalBounds().top + name.getLocalBounds().height);
        }

        void update() {
            score.setString(std::to_string(player->getScore()));
        }

        void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            states.transform *= getTransform();
            target.draw(rectangle, states);
            target.draw(name, states);
            target.draw(score, states);
        }

    protected:
        Player* player;

        sf::RectangleShape rectangle;
        sf::Text name;
        sf::Text score;
};

#endif