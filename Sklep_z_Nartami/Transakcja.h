#ifndef TRANSAKCJA_H
#define TRANSAKCJA_H

#include "Produkt.h"

class Transakcja
{
public:
    Transakcja(Produkt* produkt, int ilosc, double cena);

    virtual double obliczWartosc() const = 0;
    virtual std::string toString() const = 0;

    Produkt* produkt() const;
    int ilosc() const;
    double cena() const;

protected:
    Produkt* m_produkt;
    int m_ilosc;
    double m_cena;
};

#endif // TRANSAKCJA_H
