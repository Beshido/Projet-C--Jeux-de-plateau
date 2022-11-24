 #include "Bouton.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Blue);
    // sf::RectangleShape box(sf::Vector2f(100.f, 200.f));
    // box.setFillColor(sf::Color::Red);
    // sf::Texture backgroundTexture;
    // sf::Sprite background;
    // backgroundTexture.loadFromFile("./background.png");
    // background.setTexture(backgroundTexture);
    Bouton bouton { "Domino carré", 70.f, 70.f, 10.f, 50.f, sf::Color::Blue };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            bouton.checkClick(event);
        } 

        window.clear();
        window.draw(bouton.getRectangle());
        // window.draw(box);
        // window.draw(box);
        window.display();
    }

    return 0;
}