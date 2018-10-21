

#include "Mieszkanie.h"


Mieszkanie::Mieszkanie() {
}

Mieszkanie::Mieszkanie(const Mieszkanie& orig) {
}

Mieszkanie::~Mieszkanie() {
}
unsigned Mieszkanie::liczbaWczytanychMieszk = 0;

ostream & operator<<(ostream &s, const Mieszkanie & m){
//    s<< m.Adres<<endl;
    s<<"wlasciciel: "<<m.nazwWlasciciela<<endl;
    s<<"powierzchnia: "<<m.powierzchnia<<endl;
    s<<"l. pokoi: "<<m.liczbaPokoi<<endl;
    s<<"status: "<<(m.zamieszkane ? "zamieszkane" : "puste" )<<endl;
    return s;
}

istream & operator>>(istream &s, Mieszkanie & m){
  //  s>>m.Adres; - brak dostepu protected
    s>>m.nazwWlasciciela;
    s>>m.powierzchnia;
    s>>m.liczbaPokoi;
    s>>m.zamieszkane;

if(!s.fail())
        m.liczbaWczytanychMieszk++;
    return s;
}
 /** metoda czysto wirtualna przeciazana w mieszkaniu - dla pokazania */
void Mieszkanie::PrzeciazMnie()
{
   std::cout << "czysto Wirtualna przeciazona w Mieszkaniu "<<endl;

}
 /** metoda  wirtualna w mieszkaniu - dla pokazania */
  void Mieszkanie::wirtualna()
 {

   std::cout << "Wirtualna Mieszkanie "<<endl;


 }
