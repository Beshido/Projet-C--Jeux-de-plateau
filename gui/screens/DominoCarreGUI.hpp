#ifndef _DominoCarreGUI
#define _DominoCarreGUI

#include "cScreen.hpp"
#include "../drawable/DominoCarreTuileGUI.hpp"
#include "../../Tuile.hpp"

class DominoCarreGUI : public cScreen {
    public:
        virtual int run(sf::RenderWindow &window);
};

#endif