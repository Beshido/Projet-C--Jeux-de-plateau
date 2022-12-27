#include "TraxScreen.hpp"
#include "../drawable/Bouton.hpp"
#include "../drawable/TraxGUI.hpp"
#include "../../logic/Trax.hpp"
#include <iostream>

int TraxScreen::run(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("./fonts/SpaceMono-Regular.ttf");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./img/domino_background.jpg");
    sf::Sprite background;
    background.setTexture(backgroundTexture);


    Trax dominoCarre { 10, 2 };
    TraxGUI traxGui { &dominoCarre, &font };
    TraxGUI.setSize(window.getSize().x * 80 / 100, window.getSize().y);

    Bouton quit = Bouton { "Quitter", &font };
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
        window.draw(dominoCarreGui);
        window.display();
    }

	return -1;
}