#ifndef _TraxScreen
#define _TraxScreen

#include "cScreen.hpp"

class TraxScreen: public cScreen {
    public:
        virtual int run(sf::RenderWindow &window);
};

#endif