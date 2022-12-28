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
    boutonTrax.setTextColor(sf::Color::Black);
    boutonTrax.setRectangleColor(sf::Color::Red);

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
                    break;
                default:
                    break;
            }
        }
        window.clear();
        window.draw(background);
        window.draw(boutonDomino);
        window.draw(boutonTrax);
        window.display();
    }

	return -1;
}