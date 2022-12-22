#include "DominoCarreScreen.hpp"
#include "../drawable/DominoCarreGUI.hpp"
#include "../drawable/DominoCarreTuileGUI.hpp"
#include "../../DominoCarre.hpp"
#include "../../Tuile.hpp"

int DominoCarreScreen::run(sf::RenderWindow &window) {
    
    sf::Font font;
    font.loadFromFile("./fonts/SpaceMono-Regular.ttf");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./img/domino_background.jpg");
    sf::Sprite background;
    background.setTexture(backgroundTexture);

    const unsigned int l = 1;
    const unsigned int h = 1; 
    const unsigned int c = 10; 
    DominoCarre dominoCarre { l, h, c };
    DominoCarreGUI dominoCarreGui { &dominoCarre, &font };
    dominoCarreGui.setSize(/* 70 *  */window.getSize().y/*  / 100 */);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        } 

        window.clear();
        window.draw(background);
        window.draw(dominoCarreGui);
        window.display();
    }

	return -1;
}