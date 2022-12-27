#include "DominoCarreScreen.hpp"
#include "../drawable/DominoCarreGUI.hpp"
#include "../drawable/DominoCarreTuileGUI.hpp"
#include "../../logic/DominoCarre.hpp"
#include "../../logic/Tuile.hpp"

int DominoCarreScreen::run(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("./fonts/SpaceMono-Regular.ttf");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./img/domino_background.jpg");
    sf::Sprite background;
    background.setTexture(backgroundTexture);


    DominoCarre dominoCarre { 10, 2 };
    std::cout << "a" << std::endl;
    DominoCarreGUI dominoCarreGui { &dominoCarre, &font };
    std::cout << "a" << std::endl;
    dominoCarreGui.setSize(window.getSize().x * 80 / 100, window.getSize().y);

    std::cout << "a" << std::endl;
    Bouton quit = Bouton { "Quitter", &font };
    std::cout << "a" << std::endl;
    quit.setSize(window.getSize().x * 20 / 100, window.getSize().y * 10 / 100);
    std::cout << "a" << std::endl;
    quit.setPosition(window.getSize().x * 80 / 100, 0);
    std::cout << "a" << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
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
        window.draw(dominoCarreGui);
        window.display();
    }

	return -1;
}