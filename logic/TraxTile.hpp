#ifndef _TraxTuile
#define _TraxTuile

#include "Tile.hpp"

enum class TraxCouleur { Black, White };

class TraxTile : public Tile<TraxCouleur> {
    public:
        TraxTile();
        void flip();

    private:
        bool flipped;
};

#endif