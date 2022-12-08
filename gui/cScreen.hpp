#ifndef _cScreen
#define _cScreen

#include <SFML/Graphics.hpp>

class cScreen {
    public:
        virtual int run(sf::RenderWindow &window) = 0;
};

#endif