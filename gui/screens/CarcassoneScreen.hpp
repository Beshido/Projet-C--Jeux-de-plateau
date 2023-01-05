#ifndef _CarcassoneScreen
#define _CarcassoneScreen

#include "cScreen.hpp"

class CarcassoneScreen: public cScreen {
    public:
        virtual int run(sf::RenderWindow &window);
};

#endif