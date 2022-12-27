#ifndef _Tuile
#define _Tuile

#include <iostream>

template <typename T> class Tuile {
    protected:
        T valeurNord;
        T valeurOuest;
        T valeurEst;
        T valeurSud;
        unsigned int rotationFactor;

    public:
        Tuile(const T valeurNord, const T valeurOuest, const T valeurEst, const T valeurSud): valeurNord { valeurNord }, valeurOuest { valeurOuest }, valeurEst { valeurEst }, valeurSud { valeurSud }, rotationFactor { 0 } {}
        ~Tuile() {
            std::cout << "Destruction de Tuile." << std::endl;
        }

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
            valeurNord = valeurEst;
            valeurEst = valeurSud;
            valeurSud = valeurOuest;
            valeurOuest = temp;

            rotationFactor++;
        }
        
        void tournerDroite() {
            T temp = valeurNord;
            valeurNord = valeurOuest;
            valeurOuest = valeurSud;
            valeurSud = valeurEst;
            valeurEst = temp;

            rotationFactor--;
        }
};

#endif