#include "BazaDanych.h"
#include <iostream>
#include <fstream>

using namespace std;

BazaDanych::BazaDanych()
{
    // Wczytanie produktów z pliku
    ifstream plik("produkty.txt");
    if (plik)
    {
        string nazwa;
        double cena;
        int ilosc;
        int typ;
        string marka;
        string rozmiar;
        string kolor;
        int id;

        while (plik >> typ >> nazwa >> cena >> ilosc >> marka >> rozmiar >> kolor >> id)
        {
            if (typ == 1)
            {
                Produkt* nowyProdukt = new ProduktElektroniczny(nazwa, cena, ilosc, marka, id);
                dodajProdukt(nowyProdukt);
            }
            else if (typ == 2)
            {
                Produkt* nowyProdukt = new ProduktOdziezowy(nazwa, cena, ilosc, rozmiar, kolor, id);
                dodajProdukt(nowyProdukt);
            }
        }

        plik.close();
    }
    else
    {
        cout << "Blad wczytywania pliku." << endl;
    }
}

BazaDanych::~BazaDanych()
{
    // Zapisanie produktów do pliku
    ofstream plik("produkty.txt");
    if (plik)
    {
        for (auto& produkt : listaProduktow)
        {
            if (produkt->typ() == 1)
            {
                ProduktElektroniczny* produktElektroniczny = dynamic_cast<ProduktElektroniczny*>(produkt);
                plik << produkt->typ() << " " << produkt->nazwa() << " " << produkt->cena() << " "
                    << produkt->ilosc() << " " << produktElektroniczny->marka() << " " << produktElektroniczny->id() << endl;
            }
            else if (produkt->typ() == 2)
            {
                ProduktOdziezowy* produktOdziezowy = dynamic_cast<ProduktOdziezowy*>(produkt);
                plik << produkt->typ() << " " << produkt->nazwa() << " " << produkt->cena() << " "
                    << produkt->ilosc() << " " << produktOdziezowy->rozmiar() << " " << produktOdziezowy->kolor() << " "
                    << produktOdziezowy->id() << endl;
            }
        }

        plik.close();
    }
    else
    {
        cout << "Blad zapisu do pliku." << endl;
    }

    // Usuniecie produktow z listy i z pamieci
    for (auto& produkt : listaProduktow)
    {
        delete produkt;
    }
}
void BazaDanych::zwiekszIlosc(int id, int ilosc)
{
    for (auto& produkt : listaProduktow)
    {
        if (produkt->id() == id)
        {
            produkt->zwiekszIlosc(ilosc);

            // aktualizacja pliku bazy danych po zmianie ilości produktu
            ofstream plik("baza_danych.txt");
            if (plik.is_open())
            {
                for (const auto& p : listaProduktow)
                {
                    plik << p->typ() << ";";
                    plik << p->marka() << ";";
                    plik << p->rozmiar() << ";";
                    plik << p->kolor() << ";";
                    plik << p->id() << endl;
                }
                plik.close();
            }
            else
            {
                cout << "Nie udalo sie otworzyc pliku bazy danych." << endl;
            }
            break;
        }
    }
}
void BazaDanych::dodajProdukt(Produkt* produkt)
{
    listaProduktow.push_back(produkt);
}

void BazaDanych::usunProdukt(int id)
{
    for (auto it = listaProduktow.begin(); it != listaProduktow.end(); ++it)
    {
        if ((*it)->id() == id)
        {
            listaProduktow.erase(it);
            break;
        }
    }
}
// aktualizacja pliku bazy danych po usunięciu produktu
ofstream plik("baza_danych.txt");
if (plik.is_open())
{
    for (auto it = listaProduktow.begin(); it != listaProduktow.end(); ++it)
    {
        plik << (*it)->typ() << ";";
        plik << (*it)->marka() << ";";
        plik << (*it)->rozmiar() << ";";
        plik << (*it)->kolor() << ";";
        plik << (*it)->id() << endl;
    }
    plik.close();
}
else
{
    cout << "Nie udalo sie otworzyc pliku bazy danych." << endl;
}