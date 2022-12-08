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
        Tuile(T valeurNord, T valeurOuest, T valeurEst, T valeurSud): valeurNord { valeurNord }, valeurOuest { valeurOuest }, valeurEst { valeurEst }, valeurSud { valeurSud } {}

        T getValeurNord() {
            return valeurNord;
        }
        
        T getValeurOuest() {
            return valeurOuest;
        }
        
        T getValeurEst() {
            return valeurEst;
        }
        
        T getValeurSud() {
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