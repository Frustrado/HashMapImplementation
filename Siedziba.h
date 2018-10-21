#ifndef SIEDZIBA_H
#define SIEDZIBA_H
#include <string>
#include <istream>
#include <ostream>
#include <iostream>
using namespace std;
/**
 * @brief Klasa abstrakcyjna Siedziba
 */
class Siedziba //klasa abstrakcyjna
{
    public:
        /** Konstruktor */
        Siedziba();
        /** Destruktor */
        virtual ~Siedziba();

        /** Dostep do Adresu
         * \return Obecna wartosc adresu
         */
        string GetAdres() { return Adres; }
        /** Usaw Adres
         * \param val
         */
        void SetAdres(string val) { Adres = val; }
/** metoda  wirtualna z siedziby - dla pokazania */
  virtual void wirtualna()
    {
         cout << "Wirtualna z Siedziby \n";
    }

/** metoda czysto wirtualna - dla pokazania */
 virtual void PrzeciazMnie() = 0;/// metoda czysto wirtualna


        /**
 * @brief Przeciazenie operatora strumieniowego <<
 */
friend ostream & operator<<(ostream &s, const Siedziba &m);



    protected:
        string Adres; //!< Glowna zmienna "Adres"




};






#endif // SIEDZIBA_H
