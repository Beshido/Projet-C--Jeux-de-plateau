#ifndef _DominoCarreGUI
#define _DominoCarreGUI

#include "cScreen.hpp"
#include "../drawable/Bouton.hpp"
#include "../drawable/DominoCarreTuileGUI.hpp"
#include "../../DominoCarre.hpp"
#include "../../Tuile.hpp"

class DominoCarreGUI : public cScreen {
    public:
        DominoCarreGUI(DominoCarre* dominoCarre);
        virtual int run(sf::RenderWindow &window);

    private:
        DominoCarre* dominoCarre;
};

#endif