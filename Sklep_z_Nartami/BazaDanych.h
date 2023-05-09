#ifndef BAZADANYCH_H
#define BAZADANYCH_H

#include <vector>
#include "Produkt.h"
#include "Transakcja.h"

class BazaDanych {
public:
    void dodajProdukt(Produkt* produkt);
    void dodajTransakcje(Transakcja* transakcja);
    void wyswietlListeProduktow() const;
    Produkt* getProdukt(int id) const;
    void zapiszDoPliku(const std::string& nazwaPliku) const;
    void wczytajZPliku(const std::string& nazwaPliku);

private:
    std::vector<Produkt*> listaProduktow;
    std::vector<Transakcja*> listaTransakcji;
};

#endif
