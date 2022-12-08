#ifndef _MenuPrincipal
#define _MenuPrincipal

#include "cScreen.hpp"
#include "../drawable/Bouton.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class MenuPrincipal: public cScreen {
    public:
        virtual int run(sf::RenderWindow &window);
};

#endif