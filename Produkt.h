#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>

class Produkt
{
public:
    Produkt(const std::string& nazwa, double cena, int ilosc);

    std::string getNazwa() const;
    double getCena() const;
    int getIlosc() const;
    int getId() const;
    void zmienIlosc(int ilosc);

private:
    static int liczbaProduktow;
    int id;
    std::string nazwa;
    double cena;
    int ilosc;
};

#endif // PRODUKT_H
