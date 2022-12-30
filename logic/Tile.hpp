#ifndef _Tile
#define _Tile

#include <iostream>

template <typename P> class Tile {
    protected:
        P valeurNord;
        P valeurOuest;
        P valeurEst;
        P valeurSud;
        int rotationFactor;

    public:
        Tile(const P valeurNord, const P valeurOuest, const P valeurEst, const P valeurSud): valeurNord { valeurNord }, valeurOuest { valeurOuest }, valeurEst { valeurEst }, valeurSud { valeurSud }, rotationFactor { 0 } {}
        ~Tile() {
            std::cout << "Destruction de Tuile." << std::endl;
        }

        void tournerGauche() {
            P temp = valeurNord;
            valeurNord = valeurEst;
            valeurEst = valeurSud;
            valeurSud = valeurOuest;
            valeurOuest = temp;

            rotationFactor--;
        }
        
        void tournerDroite() {
            P temp = valeurNord;
            valeurNord = valeurOuest;
            valeurOuest = valeurSud;
            valeurSud = valeurEst;
            valeurEst = temp;

            rotationFactor++;
        }

        const P getValeurNord() const { return valeurNord; }
        const P getValeurOuest() const { return valeurOuest; }
        const P getValeurEst() const { return valeurEst; }
        const P getValeurSud() const { return valeurSud; }
        const int getRotationFactor() const { return rotationFactor; }
};

template<typename P> inline std::ostream& operator<<(std::ostream& os, const Tile<P>& tile) {
    os << tile.getValeurNord() << ", " << tile.getValeurEst() << ", " << tile.getValeurEst() << ", " << tile.getValeurSud();
    return os;
}

#endif