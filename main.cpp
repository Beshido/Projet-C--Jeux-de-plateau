#include "gui/Bouton.hpp"
#include "gui/DominoCarreTuile.hpp"
#include "DominoCarre.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    sf::Font font;
    font.loadFromFile("./fonts/arial.ttf");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./img/fleurs.png");
    sf::Sprite background;
    background.setTexture(backgroundTexture);

    Bouton boutonDomino { 70.f, 70.f, 300.f, 70.f, "Domino carre", &font };
    Bouton boutonTrax { 70.f, 200.f, 300.f, 70.f, sf::Color::Red, "Trax", &font, sf::Color::Black };

    Tuile domino { 100, 400, 300, 200 };
    DominoCarreTuile dominoGui { &domino, &font };
    dominoGui.setPosition(50, 50);

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
                dominoGui.setPosition(0, 0);
                dominoGui.setSize(200);
            }
        } 

        window.clear();
        window.draw(background);
        window.draw(boutonDomino);
        window.draw(boutonTrax);
        window.draw(dominoGui);
        window.display();
    }

    return 0;
}