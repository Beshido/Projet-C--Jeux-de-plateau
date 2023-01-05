#ifndef _Assets
#define _Assets

#include <SFML/Graphics.hpp>

class Assets {
    public:
        static sf::Texture mainBackground;
        static sf::Texture plateauBackground;
        static sf::Texture trax;
        static sf::Texture carcassone;
        static sf::Font font;

        static const bool initializeAssets();
};

#endif