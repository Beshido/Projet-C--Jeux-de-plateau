#ifndef _MenuPrincipal
#define _MenuPrincipal

#include "cScreen.hpp"

class MenuPrincipal: public cScreen {
    public:
        virtual int run(sf::RenderWindow &window);
};

#endif