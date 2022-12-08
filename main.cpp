#include "gui/Bouton.hpp"
#include "gui/screens.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Tuile.hpp"

int main() {
	std::vector<cScreen*> Screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(640, 480, 32), "SFML Demo 3");

	//Mouse cursor no more visible
	App.setMouseCursorVisible(false);

	//Screens preparations
	menuPrincipal menuPrincipal;
	Screens.push_back(&menuPrincipal);

	//Main loop
	while (screen >= 0) {
		screen = Screens[screen]->run(App);
	}

	return EXIT_SUCCESS;
}