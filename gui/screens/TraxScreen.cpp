#include "TraxScreen.hpp"
#include "../Assets.hpp"
#include "../drawable/PlayerShape.hpp"
#include "../drawable/TraxTileShape.hpp"
#include "../drawable/PlateauShape.hpp"
#include "../../logic/Trax.hpp"
#include "../../logic/TraxTile.hpp"
#include <iostream>

int TraxScreen::run(sf::RenderWindow &window) {    
    sf::Sprite background;
    background.setTexture(Assets::mainBackground);

    Trax trax {};
    PlateauShape<Trax, TraxTileShape, PlayerShape<Joueur<TraxTile>>> traxGui { &trax };
    traxGui.setSize(window.getSize().x * 80 / 100, window.getSize().y);

    Bouton quit = Bouton { "Quitter" };
    quit.setSize(window.getSize().x * 20 / 100, window.getSize().y * 10 / 100);
    quit.setPosition(window.getSize().x * 80 / 100, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    traxGui.setSize(event.size.width * 80 / 100, event.size.height);
                    quit.setSize(event.size.width * 20 / 100, event.size.height * 10 / 100);
                    break;
                case sf::Event::MouseButtonPressed:
                    traxGui.fireEvent(event.mouseButton);
                    if (quit.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                        std::cout << "Retour au menu principal." << std::endl;
                        return 0;
                    }
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.draw(background);
        window.draw(quit);
        window.draw(traxGui);
        window.display();
    }

	return -1;
}