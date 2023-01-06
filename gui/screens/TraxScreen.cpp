#include "TraxScreen.hpp"
#include "../Assets.hpp"
#include "../drawable/PlayerShape.hpp"
#include "../drawable/TraxPlateauShape.hpp"
#include "../drawable/TraxTileShape.hpp"
#include "../drawable/PlateauShape.hpp"
#include "../../logic/Trax.hpp"
#include "../../logic/TraxTile.hpp"
#include <iostream>

int TraxScreen::run(sf::RenderWindow &window) {    
    sf::Sprite background;
    background.setTexture(Assets::traxBackground);

    Trax trax {};
    TraxPlateauShape traxGui { &trax };
    traxGui.setSize(window.getSize().x * 80 / 100, window.getSize().y);

    Bouton quit = Bouton { "Quitter", sf::Color::Black, sf::Color::Red };
    quit.setSize(window.getSize().x * 20 / 100, window.getSize().y * 10 / 100);
    quit.setPosition(window.getSize().x * 80 / 100, 0);
    sf::Sprite traxPanel { Assets::traxPanel };
    traxPanel.setScale(0.6f, 0.6f);
    traxPanel.setPosition(window.getSize().x * 80 / 100, window.getSize().y * 10 / 100);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    GC::nettoie();
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
        window.draw(traxPanel);
        window.draw(traxGui);
        window.display();
    }

	return -1;
}