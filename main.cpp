#include "gui/drawable/Bouton.hpp"
#include "gui/screens/screens.hpp"
#include "Tuile.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

const std::string WINDOW_NAME = "Jeux de tuile";
const unsigned int WINDOW_WIDTH = 1280;
const unsigned int WINDOW_HEIGHT = 720;

int main() {
	std::vector<cScreen*> screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), WINDOW_NAME);

	//Mouse cursor no more visible
	window.setMouseCursorVisible(false);

	//Screens preparations
	MenuPrincipal menuPrincipal;
	DominoCarreScreen dominoCarreGUI;
	screens.push_back(&menuPrincipal);
	screens.push_back(&dominoCarreGUI);

	//Main loop
	while (screen >= 0) {
		screen = screens[screen]->run(window);
	}

	return EXIT_SUCCESS;
}