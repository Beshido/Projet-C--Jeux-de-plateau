#include "cScreen.hpp"
#include "../drawable/Bouton.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#ifndef _MenuPrincipal
#define _MenuPrincipal

class MenuPrincipal: public cScreen {
    public:
        virtual int run(sf::RenderWindow &window);
};

#endif