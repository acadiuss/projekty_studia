#include "Transakcja.h"

Transakcja::Transakcja(Produkt* produkt, int ilosc, double cena)
    : m_produkt(produkt), m_ilosc(ilosc), m_cena(cena)
{}

Produkt* Transakcja::produkt() const
{
    return m_produkt;
}

int Transakcja::ilosc() const
{
    return m_ilosc;
}

double Transakcja::cena() const
{
    return m_cena;
}