#include "gui/drawable/Bouton.hpp"
#include "gui/screens/screens.hpp"
#include "Tuile.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

int main() {
	std::vector<cScreen*> screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML Demo 3");

	//Mouse cursor no more visible
	window.setMouseCursorVisible(false);

	//Screens preparations
	MenuPrincipal menuPrincipal;
	DominoCarreGUI dominoCarreGUI;
	screens.push_back(&menuPrincipal);
	screens.push_back(&dominoCarreGUI);

	//Main loop
	while (screen >= 0) {
		screen = screens[screen]->run(window);
	}

	return EXIT_SUCCESS;
}