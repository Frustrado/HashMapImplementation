#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>

#include "Mieszkanie.h"
#include "MieszkanieHipoteczne.h"
#include "MieszkanieWynajmowane.h"
#include "HashSet.h"
#include "HashSet.cpp"

using namespace std;

/**
 * @brief Funkcja zczytujaca ciagi znakow.
 *@param obiekt
 *@param wejsciowy ciag znakow
 */
template <class T>
void readFromString(HashSet<T> &h, string input){
    T temp;

    istringstream f(input);

    while(!f.eof()){
            f>>temp;
            h.add(temp);
    };
}
/**
 * @brief main() zawiera podstawowe testy ktore sa wykonywane na obiektach
 */
int main() {
    HashSet<Mieszkanie> h;
    HashSet<Mieszkanie> h2;

    readFromString(h,"Kowalski 120.5 4 0 Marciniak 55 2 1");
    readFromString(h2, "Wojciechowski 72 3 0 Marciniak 55 20 1");


    HashSet<Mieszkanie> h3 = h2-h;
    h3.printSet();
    HashSet<Mieszkanie> h4 = h*h2;
    h4.printSet();
    HashSet<Mieszkanie> h5 = h+h2;

    cout<<"\nh3 length:"<<h4.length()<<endl;

    cout<<endl<<"Wczytano mieszkan z pliku:"<< Mieszkanie::liczbaWczytanychMieszk<<endl;


    //   klasa abstrakcyjna -  nie mozna tworzyc  jej obiektow

   /* Siedziba *wskSiedziba = new Siedziba();
    wskSiedziba->SetAdres("ul. Korzenna 11, 01-111 Warszawa");
    cout<<wskSiedziba<<endl;
    cout<<*wskSiedziba<<endl;
    delete wskSiedziba;*/

    // Wskaznik klasy bazowej
    Mieszkanie * wskMieszkanie = new Mieszkanie();
    wskMieszkanie->SetAdres("ul. Korzenna 12, 01-111 Warszawa");
    wskMieszkanie->liczbaPokoi=1;
    wskMieszkanie->powierzchnia=40;
    wskMieszkanie->zamieszkane=true;

    cout<<wskMieszkanie<<endl;// co gdy wyswietlamy wskaznik
    cout<<*wskMieszkanie;// dereferencja wskaznika
    delete wskMieszkanie;//zwoleninei pamieci po zaaalokowanej pamieci

  // Wskazniki klasy pochodnej 2 poziom


    MieszkanieHipoteczne * wskMieszkanieHipoteczne = new MieszkanieHipoteczne();
    wskMieszkanieHipoteczne->SetAdres("ul. Korzenna 12, 01-111 Warszawa");
    wskMieszkanieHipoteczne->liczbaPokoi=1;
    wskMieszkanieHipoteczne->powierzchnia=40;
    wskMieszkanieHipoteczne->zamieszkane=true;
     wskMieszkanieHipoteczne->SetPodatek(321);

    cout<<wskMieszkanieHipoteczne<<endl;// co gdy wyswietlamy wskaznik
    cout<<*wskMieszkanieHipoteczne;// dereferencja wskaznika
    delete wskMieszkanieHipoteczne;//zwoleninei pamieci po zaaalokowanej pamieci


    MieszkanieWynajmowane * wskMieszkanieWynajmowane = new MieszkanieWynajmowane();
    wskMieszkanieWynajmowane->SetAdres("ul. Korzenna 12, 01-111 Warszawa");
    wskMieszkanieWynajmowane->liczbaPokoi=1;
    wskMieszkanieWynajmowane->powierzchnia=40;
    wskMieszkanieWynajmowane->zamieszkane=true;
    wskMieszkanieWynajmowane->SetCzynsz(123);

    cout<<wskMieszkanieWynajmowane<<endl;// co gdy wyswietlamy wskaznik
    cout<<*wskMieszkanieWynajmowane;// dereferencja wskaznika
    delete wskMieszkanieWynajmowane;//zwoleninei pamieci po zaaalokowanej pamieci



    //Konwersja w górę
    MieszkanieWynajmowane mw;
Mieszkanie m, * mm;
m = mw; //rzutowanie w górę obiektu
mm = & mw; //rzutowanie w górę adresu

//Rzutowanie w dół

MieszkanieWynajmowane mw1, * mwp1;
Mieszkanie * m1;

m1 = & mw1; //w gore na bazowa

mwp1 = dynamic_cast < MieszkanieWynajmowane *>( m1 );

if( mwp1 == 0 )
{
  cout<<"obiekt pod adresem p nie jest typu MieszkanieWynajmowane"<<endl;
}
else
{
   cout<<"obiekt pod adresem p  jest typu  MieszkanieWynajmowane"<<endl;
}






/////////////Metody wirtualne

 Mieszkanie * mb = new MieszkanieHipoteczne();

    mb->wirtualna(); //wskaźnik typu B, metoda z P
    delete mb;




/////////////Metody czysto wirtualne

 Mieszkanie * mb1 = new MieszkanieHipoteczne();

    mb1->PrzeciazMnie(); //wskaźnik typu B, metoda z P
    delete mb1;




//Wyjatki





//iterator
cout<<endl<<"-------------Pokaz kontener z bez iteratora---------------------"<<endl;
h5.printSet();


  cout<<endl<<"-------------Pokaz kontenera z   iteratorem---------------------"<<endl;
  ListIterator<Mieszkanie>* it2=h5.createIterator();
  //new ListIterator<Mieszkanie>(&h);
  //h.createIterator();

//cout<<"ile = "<<it2->lenght()<<endl;

cout<<it2->End()->s;
cout<<"Index ostatniego elementu="<<it2->getIndex()-1<<endl<<endl<<endl;


cout<<it2->Begin()->s;
cout<<"Index pierwszego elementu="<<it2->getIndex()<<endl<<endl<<endl;


//wyswietlenei wszystkich elementow
//while
     while (it2->hasNext()){
     cout<<it2->currentItem()->s<<endl;
     cout<<"Index="<<it2->getIndex()<<endl<<endl;
     it2->Next(); //pprzejscie na nastepny lement
     }

cout<<"koniec wyswietlania przez iterator"<<endl;
delete it2;



  ListIterator<Mieszkanie>* it3=h.createIterator();
  it3->Begin();

h.remove(it3->Begin()->s);
h.printSet();

h.remove(it3->Begin()->s);
cout<<"czy kontener pusty?"<<endl;
h.printSet();
cout<<"tak pusty"<<endl;


//obsługa wyjatkow

try
 {
h.remove(it3->Begin()->s);
 }
catch(Mieszkanie err)
{
 cout<<"proba usuniecia nie istniejacego juz elementu (kod bledu "<<err<<")"<<endl;
}
catch(string err1)
{
cout<<"napotkano blad "<< err1 <<endl;
}

try
 {

h2.remove(it3->Begin()->s);
 }
catch(Mieszkanie err)
{
 cout<<"proba usuniecia nie istniejacego juz elementu (kod bledu "<<err<<")"<<endl;
}
catch(string err1)
{
cout<<"napotkano blad "<< err1 <<endl;
}


 try
 {
 h2.add(it3->Begin()->s);
 }
catch(Mieszkanie err)
{
 cout<<"proba dodania nie istniejacego   elementu (kod bledu "<<err<<")"<<endl;
}
catch(string err1)
{
cout<<"napotkano blad "<< err1 <<endl;
}



delete it3;




    return 0;
}


