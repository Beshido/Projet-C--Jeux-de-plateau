#ifndef _TraxPlayerShape
#define _TraxPlayerShape

#include "PlayerShape.hpp"
#include "../../logic/TraxTile.hpp"
#include "../../logic/Joueur.hpp"
#include <SFML/Graphics.hpp>

class TraxPlayerShape: public PlayerShape<Joueur<TraxTile>> {
};

#endif