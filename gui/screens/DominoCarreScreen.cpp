#include "DominoCarreScreen.hpp"
#include "../Assets.hpp"
#include "../drawable/DominoCarreTileShape.hpp"
#include "../drawable/DominoCarrePlateauShape.hpp"
#include "../drawable/PlateauShape.hpp"
#include "../../logic/DominoCarre.hpp"

int DominoCarreScreen::run(sf::RenderWindow &window) {
    sf::Sprite background;
    background.setTexture(Assets::dominoBackground);

    DominoCarre dominoCarre { 10, 2 };
    DominoCarrePlateauShape dominoCarreGui { &dominoCarre };
    dominoCarreGui.setSize(window.getSize().x * 80 / 100, window.getSize().y);

    Bouton quit = Bouton { "Quitter", sf::Color::Black, sf::Color::Green };
    quit.setSize(window.getSize().x * 20 / 100, window.getSize().y * 10 / 100);
    quit.setPosition(window.getSize().x * 80 / 100, 0);
    sf::Sprite domino { Assets::dominoPanel };
    domino.setScale(0.6f, 0.6f);
    domino.setPosition(window.getSize().x * 80 / 100, window.getSize().y * 10 / 100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    GC::nettoie();  
                    window.close();
                    break;
                case sf::Event::Resized:
                    dominoCarreGui.setSize(event.size.width * 80 / 100, event.size.height);
                    quit.setSize(event.size.width * 20 / 100, event.size.height * 10 / 100);
                    break;
                case sf::Event::MouseButtonPressed:
                    dominoCarreGui.fireEvent(event.mouseButton);
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
        window.draw(domino);
        window.draw(dominoCarreGui);
        window.display();
    }

	return -1;
}