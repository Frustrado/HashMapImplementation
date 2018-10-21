
#include <string>
#include <istream>
#include <ostream>
#include <iostream>
#include "Siedziba.h"
using namespace std;

#ifndef MIESZKANIE_H
#define MIESZKANIE_H
/**
 * @brief Klasa reprezentujaca mieszkanie
 */
class Mieszkanie: public virtual Siedziba {
public:
    /**
 * @brief Konstruktor
 */
    Mieszkanie();
    /**
 * @brief Konstruktor kopiujacy
 */

    Mieszkanie(const Mieszkanie& orig);
    /**
 * @brief Destruktor czyszczacy pamiec
 */
   /* virtual*/ ~Mieszkanie();
/**
 * @brief Porownuje czy nie bylo juz danego wystapienia
 * @param Obiekt
 *@return Prawde jesli warunki zostaly spelnione w przeciwnym przypadku falsz
 */
    bool operator !=(const Mieszkanie & m2){
        if(
                this->liczbaPokoi != m2.liczbaPokoi ||
                this->nazwWlasciciela != m2.nazwWlasciciela ||
                this->powierzchnia != m2.powierzchnia ||
                this->zamieszkane != m2.zamieszkane
            )
            return true;
        else return false;
    };


     virtual void wirtualna();
     void PrzeciazMnie(); //czysto wirtualna z klasy bazowej

//private:
    string nazwWlasciciela;
    float powierzchnia;
    int liczbaPokoi;
    bool zamieszkane;
static unsigned liczbaWczytanychMieszk;
};

/**
 * @brief Przeciazenie operatora strumieniowego <<
 */
ostream & operator<<(ostream &s, const Mieszkanie & m);
/**
 * @brief Przeciazenie operatora strumieniowego >>
 */
istream & operator>>(istream &s, Mieszkanie & m);

#endif /* MIESZKANIE_H */

