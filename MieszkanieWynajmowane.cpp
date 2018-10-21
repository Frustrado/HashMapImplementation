#include "MieszkanieWynajmowane.h"

MieszkanieWynajmowane::MieszkanieWynajmowane()
{
    //konstruktor
}

MieszkanieWynajmowane::~MieszkanieWynajmowane()
{
    //destruktor
}

MieszkanieWynajmowane::MieszkanieWynajmowane(const MieszkanieWynajmowane& other)
{
    //konstruktor kopujacy
}

MieszkanieWynajmowane& MieszkanieWynajmowane::operator=(const MieszkanieWynajmowane& rhs)
{
    if (this == &rhs) return *this;
    //operator przypisania
    return *this;
}



ostream &  operator<<(ostream &s, const MieszkanieWynajmowane &m)
{

   s<<"wlasciciel: "<<m.nazwWlasciciela<<endl;
    s<<"powierzchnia: "<<m.powierzchnia<<endl;
    s<<"l. pokoi: "<<m.liczbaPokoi<<endl;
    s<<"status: "<<(m.zamieszkane ? "zamieszkane" : "puste" )<<endl;
    s<<"czynsz: "<<m.Czynsz<<endl;
    return s;


}
//istream &  operator>>(istream &s, const MieszkanieWynajmowane &m)

