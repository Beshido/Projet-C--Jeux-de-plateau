#include "./cScreen.hpp"
#include "./Bouton.hpp"
#include "./DominoCarreTuileGUI.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "./../Tuile.hpp"

#ifndef _menuPrincipal
#define _menuPrincipal

class menuPrincipal: public cScreen {
    public:
        virtual int run(sf::RenderWindow &window);
};

#endif