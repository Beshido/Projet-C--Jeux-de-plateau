#ifndef _TraxTuile
#define _TraxTuile

#include "Tuile.hpp"

enum class TraxCouleur { Black, White };

class TraxTuile : public Tuile<TraxCouleur> {
    public:
        TraxTuile();
        void flip();

    private:
        bool flipped;
};

#endif