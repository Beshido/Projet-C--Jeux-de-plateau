#include "MenuPrincipal.hpp"

int MenuPrincipal::run(sf::RenderWindow &window) {
	sf::Font font;
    font.loadFromFile("./fonts/SpaceMono-Regular.ttf");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./img/fleurs.png");
    sf::Sprite background;
    background.setTexture(backgroundTexture);

    Bouton boutonDomino { "Domino carre", &font };
    boutonDomino.setPosition(70.f, 70.f);
    boutonDomino.setSize(300.f, 70.f);
    Bouton boutonTrax { "Trax", &font };
    boutonTrax.setPosition(70.f, 200.f);
    boutonTrax.setSize(300.f, 70.f);
    boutonTrax.setTextColor(sf::Color::Black);
    boutonTrax.setRectangleColor(sf::Color::Red);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (boutonDomino.isClicked(event)) {
                std::cout << "Le bouton Domino a été cliqué !" << std::endl;
                return 1;
            }
            if (boutonTrax.isClicked(event)) {
                std::cout << "Le bouton Trax a été cliqué !" << std::endl;
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