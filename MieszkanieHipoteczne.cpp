#include "MieszkanieHipoteczne.h"

MieszkanieHipoteczne::MieszkanieHipoteczne()
{
    //konstruktor
}

MieszkanieHipoteczne::~MieszkanieHipoteczne()
{
    //destruktor
}

MieszkanieHipoteczne::MieszkanieHipoteczne(const MieszkanieHipoteczne& other)
{
    //konstruktor kopiujacy
}

MieszkanieHipoteczne& MieszkanieHipoteczne::operator=(const MieszkanieHipoteczne& rhs)
{
    if (this == &rhs) return *this;
    //operator przypisania
    return *this;
}
