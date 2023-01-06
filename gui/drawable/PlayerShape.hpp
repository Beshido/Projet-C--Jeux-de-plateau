#ifndef _PlayerShape
#define _PlayerShape

#include "../Assets.hpp"
#include "../../logic/Joueur.hpp"
#include <SFML/Graphics.hpp>

template <typename Player> class PlayerShape: public sf::Drawable, public sf::Transformable {
    public:
        PlayerShape(Player* player, const sf::Color color1, const sf::Color color2): player { player }, color1 { color1 }, color2 { color2 } {
            rectangle.setFillColor(color1);
            rectangle.setOutlineColor(color1);
            rectangle.setOutlineThickness(3);

            name.setFont(Assets::font);
            name.setFillColor(color2);
            name.setString(player->getName());
            score.setFont(Assets::font);
            score.setFillColor(color2);

            update();
        }
        
        void active() {
            rectangle.setOutlineColor(color2);
        }

        void inactive() {
            rectangle.setOutlineColor(color1);
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

        sf::Color color1;
        sf::Color color2;
};

#endif