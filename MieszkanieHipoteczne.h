#ifndef MIESZKANIEHIPOTECZNE_H
#define MIESZKANIEHIPOTECZNE_H

#include "Mieszkanie.h"
#include <string>
#include <istream>
#include <ostream>
using namespace std;
/**
 * @brief Klasa MieszkanieHipoteczne
 */
class MieszkanieHipoteczne final: public Mieszkanie
{
    public:
        /** Konstruktor */
        MieszkanieHipoteczne();
        /** Destruktor */
        virtual ~MieszkanieHipoteczne();
        /** Konstruktor kopiujacy
         *  \param obiekt do skopiowania
         */
        MieszkanieHipoteczne(const MieszkanieHipoteczne& other);
        /** Operator przypisania
         *  \param inny obiekt do przypisania od
         *  \return Referencja do niego
         */
        MieszkanieHipoteczne& operator=(const MieszkanieHipoteczne& other);

        /** Dostep do podatku
         * \return Obecna wartosc podatku
         */
        float GetPodatek() { return Podatek; }
        /** Ustaw wartosc podatku
         * \param val
         */
        void SetPodatek(float val) { Podatek = val; }

/** metoda czysto wirtualna przeciazana w mieszkaniuhipotecznym - dla pokazania */
        void PrzeciazMnie()
{
   cout << "czysto Wirtualna przeciazona w MieszkaniuHipotecznym "<<endl;

}


    protected:

    private:
        float Podatek; //!< Glowna zmienna "Podatek"
};

#endif // MIESZKANIEHIPOTECZNE_H
