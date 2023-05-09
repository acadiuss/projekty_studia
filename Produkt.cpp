#include "Produkt.h"

Produkt::Produkt(string nazwa, double cena, int ilosc)
{
    this->nazwa = nazwa;
    this->cena = cena;
    this->ilosc = ilosc;
    this->id = ++licznikId;
}

int Produkt::getIlosc() const
{
    return ilosc;
}

double Produkt::getCena() const
{
    return cena;
}

int Produkt::getId() const
{
    return id;
}

void Produkt::zmniejszIlosc(int ilosc)
{
    this->ilosc -= ilosc;
}

void Produkt::zwiekszIlosc(int ilosc)
{
    this->ilosc += ilosc;
}

string Produkt::getNazwa() const
{
    return nazwa;
}

int Produkt::licznikId = 0;
