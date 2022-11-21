#include <SFML/Graphics.hpp>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Blue);
    // sf::RectangleShape box(sf::Vector2f(100.f, 200.f));
    // box.setFillColor(sf::Color::Red);
    sf::Texture backgroundTexture;
    sf::Sprite background;
    backgroundTexture.loadFromFile("./background.png");
    background.setTexture(backgroundTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        // window.draw(box);
        window.display();
    }

    return 0;
}