#ifndef _Tuile
#define _Tuile

#include "Tuile.hpp"

using namespace std;

template <typename T> class Tuile {
    private:
        T valeurNord;
        T valeurOuest;
        T valeurEst;
        T valeurSud;

    public:
        Tuile(const T valeurNord, const T valeurOuest, const T valeurEst, const T valeurSud): valeurNord { valeurNord }, valeurOuest { valeurOuest }, valeurEst { valeurEst }, valeurSud { valeurSud } {}

        const T getValeurNord() const {
            return valeurNord;
        }
        
        const T getValeurOuest() const {
            return valeurOuest;
        }
        
        const T getValeurEst() const {
            return valeurEst;
        }
        
        const T getValeurSud() const {
            return valeurSud;
        }

        void tournerGauche() {
            T temp = valeurNord;
            valeurNord = valeurOuest;
            valeurOuest = valeurSud;
            valeurSud = valeurEst;
            valeurEst = temp;
        }
        
        void tournerDroite() {
            T temp = valeurNord;
            valeurNord = valeurEst;
            valeurEst = valeurSud;
            valeurSud = valeurOuest;
            valeurOuest = temp;
        }
};

#endif