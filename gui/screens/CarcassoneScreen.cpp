#include "CarcassoneScreen.hpp"
#include "../Assets.hpp"
#include "../drawable/CarcassoneTileShape.hpp"
#include "../drawable/CarcassonePlateauShape.hpp"
#include "../drawable/CarcassoneTileShape.hpp"
#include "../../logic/Carcassone.hpp"

int CarcassoneScreen::run(sf::RenderWindow &window) {
    sf::Sprite background { Assets::carcassoneBackground };

    Carcassone carcassone {};
    CarcassonePlateauShape carcassoneGui { &carcassone };
    carcassoneGui.setSize(window.getSize().x * 80 / 100, window.getSize().y);

    Bouton quit = Bouton { "Quitter", sf::Color::Cyan, sf::Color::White };
    quit.setSize(window.getSize().x * 20 / 100, window.getSize().y * 10 / 100);
    quit.setPosition(window.getSize().x * 80 / 100, 0);
    sf::Sprite carcassonePanel { Assets::carcassonePanel };
    carcassonePanel.setScale(0.6f, 0.6f);
    carcassonePanel.setPosition(window.getSize().x * 80 / 100, window.getSize().y * 10 / 100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    GC::nettoie();
                    window.close();
                    break;
                case sf::Event::Resized:
                    carcassoneGui.setSize(event.size.width * 80 / 100, event.size.height);
                    quit.setSize(event.size.width * 20 / 100, event.size.height * 10 / 100);
                    break;
                case sf::Event::MouseButtonPressed:
                    carcassoneGui.fireEvent(event.mouseButton);
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
        window.draw(carcassonePanel);
        window.draw(carcassoneGui);
        window.display();
    }

	return -1;
}