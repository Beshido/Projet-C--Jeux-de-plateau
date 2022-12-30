#include "MenuPrincipal.hpp"
#include "../Assets.hpp"
#include "../drawable/Bouton.hpp"
#include <iostream>

int MenuPrincipal::run(sf::RenderWindow &window) {
    window.setFramerateLimit(30);

    sf::Sprite background;
    background.setTexture(Assets::mainBackground);

    Bouton boutonDomino { "Domino carre" };
    boutonDomino.setPosition(70.f, 70.f);
    boutonDomino.setSize(300.f, 70.f);
    Bouton boutonTrax { "Trax" };
    boutonTrax.setPosition(70.f, 200.f);
    boutonTrax.setSize(300.f, 70.f);
    boutonTrax.setRectangleColor(sf::Color::Red);
    Bouton boutonCarcassone { "Carcassone" };
    boutonCarcassone.setPosition(70.f, 330.f);
    boutonCarcassone.setSize(300.f, 70.f);
    boutonCarcassone.setRectangleColor(sf::Color::Yellow);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (boutonDomino.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                        std::cout << "Le bouton Domino a été cliqué !" << std::endl;
                        return 1;
                    }
                    else if (boutonTrax.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                        std::cout << "Le bouton Trax a été cliqué !" << std::endl;
                        return 2;
                    }
                    else if (boutonCarcassone.isClicked(event.mouseButton.x, event.mouseButton.y)) {
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
        window.draw(boutonDomino);
        window.draw(boutonTrax);
        window.draw(boutonCarcassone);
        window.display();
    }

	return -1;
}