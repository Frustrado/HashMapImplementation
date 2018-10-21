#ifndef MIESZKANIEWYNAJMOWANE_H
#define MIESZKANIEWYNAJMOWANE_H

#include "Mieszkanie.h"
#include <string>
#include <istream>
#include <ostream>
using namespace std;
/**
 * @brief Klasa MieszkanieWynajmowane
 */
class MieszkanieWynajmowane : public Mieszkanie
{
    public:
        /** Konstructor */
        MieszkanieWynajmowane();
        /** Destructor */
        virtual ~MieszkanieWynajmowane();
        /** Konstruktor kopiujacy
         *  \param inny obiekt do kopiowania
         */
        MieszkanieWynajmowane(const MieszkanieWynajmowane& other);
        /** Operator przypisania
         *  \param inny obiekt do przypisania od
         *  \return Referencja do niego
         */
        MieszkanieWynajmowane& operator=(const MieszkanieWynajmowane& other);

        /** Dostep do czynszu
         * \return Obecna wartosc czynszu
         */
        float GetCzynsz() { return Czynsz; }
        /** Ustaw czynsz
         * \param val
         */
        void SetCzynsz(float val) { Czynsz = val; }
        /** Dostep do nazwy wynajmujacego
         * \return Obecna nazwa wynajmujacego
         */
        string GetnazwWynajmujacego() { return nazwWynajmujacego; }
        /** Ustaw nazwe wynajmujacego
         * \param val
         */
        void SetnazwWynajmujacego(string val) { nazwWynajmujacego = val; }


        friend ostream & operator<<(ostream &s, const MieszkanieWynajmowane &m);
        friend istream & operator>>(istream &s, MieszkanieWynajmowane & m){

       s>>m.nazwWlasciciela;
       s>>m.powierzchnia;
       s>>m.liczbaPokoi;
       s>>m.zamieszkane;

if(!s.fail())
        m.liczbaWczytanychMieszk++;
        s>>m.Czynsz;
        return s;
        }

/** metoda czysto wirtualna przeciazana w mieszkaniu wynajmowanym - dla pokazania */
  void PrzeciazMnie()
{
   cout << "czysto Wirtualna przeciazona w MieszkanieWynajmowane "<<endl;

}

    protected:

    private:
        float Czynsz; //!< Glowna zmienna "Czynsz"
        string nazwWynajmujacego; //!< Glowna zmienna "nazwWynajmujacego"
};

#endif // MIESZKANIEWYNAJMOWANE_H
