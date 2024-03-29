#include "gui/Assets.hpp"
#include "gui/drawable/Bouton.hpp"
#include "gui/screens/screens.hpp"
#include "logic/Tile.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

const std::string WINDOW_NAME = "Jeux de tuile";
const unsigned int WINDOW_WIDTH = 1280;
const unsigned int WINDOW_HEIGHT = 720;

int main() {
    if (!Assets::initializeAssets()) {
        return EXIT_FAILURE;
    }
    std::cout << "Assets chargés avec succès." << std::endl;

	std::vector<cScreen*> screens;
	int screen = 0;

	//Window creation
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), WINDOW_NAME);

	//Mouse cursor no more visible
	window.setMouseCursorVisible(false);

	//Screens preparations
	MenuPrincipal menuPrincipal;
	DominoCarreScreen dominoCarreGUI;
    TraxScreen traxGUI;
    CarcassoneScreen carcassoneGUI;
	screens.push_back(&menuPrincipal);
	screens.push_back(&dominoCarreGUI);
    screens.push_back(&traxGUI);
    screens.push_back(&carcassoneGUI);

	//Main loop
	while (screen >= 0) {
		screen = screens.at(screen)->run(window);
	}

	return EXIT_SUCCESS;
}