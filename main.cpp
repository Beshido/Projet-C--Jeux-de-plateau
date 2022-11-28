#include "Bouton.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    sf::Font font;
    font.loadFromFile("./fonts/Agatha.ttf");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./img/fleurs.png");
    sf::Sprite background;
    background.setTexture(backgroundTexture);

    Bouton boutonDomino { 70.f, 70.f, 300.f, 70.f, "Domino carre", &font };
    Bouton boutonTrax { 70.f, 200.f, 300.f, 70.f, sf::Color::Red, "Trax", &font, sf::Color::Black };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (boutonDomino.checkClick(event)) {
                std::cout << "Le bouton Domino a été cliqué !" << std::endl;
            }
            if (boutonTrax.checkClick(event)) {
                std::cout << "Le bouton Trax a été cliqué !" << std::endl;
            }
        } 

        window.clear();
        window.draw(background);
        window.draw(boutonDomino);
        window.draw(boutonTrax);
        window.display();
    }

    return 0;
}