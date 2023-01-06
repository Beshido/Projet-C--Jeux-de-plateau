#include "MenuPrincipal.hpp"
#include "../Assets.hpp"
#include "../drawable/Bouton.hpp"
#include <iostream>

int MenuPrincipal::run(sf::RenderWindow &window) {
    window.setFramerateLimit(30);

    sf::Sprite background;
    background.setTexture(Assets::mainBackground);

    sf::Sprite domino;
    domino.setTexture(Assets::dominoPanel);

    sf::Sprite trax;
    trax.setTexture(Assets::traxPanel);
    trax.setPosition(domino.getTextureRect().width, 0);

    sf::Sprite carcassone;
    carcassone.setTexture(Assets::carcassonePanel);
    carcassone.setPosition(domino.getTextureRect().width + trax.getTextureRect().width, 0);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (domino.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        std::cout << "Le bouton Domino a été cliqué !" << std::endl;
                        return 1;
                    }
                    else if (trax.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        std::cout << "Le bouton Trax a été cliqué !" << std::endl;
                        return 2;
                    }
                    else if (carcassone.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        std::cout << "Le bouton Carcassone a été cliqué !" << std::endl;
                        return 3;
                    }
                    break;
                default:
                    break;
            }
        }
        window.clear();
        window.draw(background);
        window.draw(domino);
        window.draw(trax);
        window.draw(carcassone);
        window.display();
    }

	return -1;
}