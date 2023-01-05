#ifndef _TraxTile
#define _TraxTile

#include "Tile.hpp"

enum class TraxCouleur { Black = 0, White = 1 };
inline std::ostream& operator<<(std::ostream& os, const TraxCouleur& TraxCouleur) {
    switch (TraxCouleur) {
        case TraxCouleur::Black:
            os << "Noir";
            break;
        case TraxCouleur::White:
            os << "Blanc";
            break;
    }
    return os;
}

class TraxTile : public Tile<TraxCouleur> {
    public:
        TraxTile(const bool flipped = false);
        const bool flip();
        const bool isFlipped() const;

    private:
        bool flipped;
};

#endif