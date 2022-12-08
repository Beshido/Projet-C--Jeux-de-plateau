#include "DominoCarreGUI.hpp"

DominoCarreGUI::DominoCarreGUI(DominoCarre* dominoCarre): dominoCarre { dominoCarre } {}

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

    Bouton sacTuile { 300, 400, 500, 50, "piocher dans le sac lol", &font };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sacTuile.isClicked(event)) {
                std::cout << "za3ma ca tente de piocher ???" << std::endl;
            }
        } 

        window.clear();
        window.draw(background);
        window.draw(dominoGui);
        window.draw(sacTuile);
        window.display();
    }

	return -1;
}