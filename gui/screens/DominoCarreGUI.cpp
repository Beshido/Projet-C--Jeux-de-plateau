#include "DominoCarreGUI.hpp"

int DominoCarreGUI::run(sf::RenderWindow &window) {

    sf::Font font;
    font.loadFromFile("./fonts/SpaceMono-Regular.ttf");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./img/domino_background.jpg");
    sf::Sprite background;
    background.setTexture(backgroundTexture);

    Tuile<int> domino { 100, 400, 300, 200 };
    DominoCarreTuileGUI dominoGui { &domino, &font };
    dominoGui.setPosition(50, 50);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        } 

        window.clear();
        window.draw(background);
        window.draw(dominoGui);
        window.display();
    }

	return -1;
}