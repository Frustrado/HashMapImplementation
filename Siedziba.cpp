#include "Siedziba.h"

Siedziba::Siedziba()
{
    //konstruktor
}

Siedziba::~Siedziba()
{
    //destruktor
}



  ostream & operator<<(ostream &s,const Siedziba &m){
    s<< m.Adres<<endl;

    return s;
}

  //istream & operator>>(istream &s,const Siedziba &m)

