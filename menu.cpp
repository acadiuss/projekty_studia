#include <iostream>
#include "BazaDanych.h"
#include "Kupno.h"
#include "Wypozyczenie.h"
#include "Raport.h"

using namespace std;

int main()
{
    BazaDanych bazaDanych;

    while (true)
    {
        cout << "Menu glowne" << endl;
        cout << "1. Dodaj produkt" << endl;
        cout << "2. Kupno" << endl;
        cout << "3. Wypozyczenie" << endl;
        cout << "4. Generuj raport" << endl;
        cout << "5. Zwieksz ilosc produktu" << endl;
        cout << "6. Zakoncz program" << endl;

        int wybor;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
            case 1:
            {
                string nazwa;
                double cena;
                int ilosc;
                cout << "Podaj nazwe produktu: ";
                cin >> nazwa;
                cout << "Podaj cene produktu: ";
                cin >> cena;
                cout << "Podaj ilosc produktu: ";
                cin >> ilosc;

                Produkt* nowyProdukt = new Produkt(nazwa, cena, ilosc);
                bazaDanych.dodajProdukt(nowyProdukt);
                break;
            }

            case 2:
            {
                cout << "Kupno" << endl;
                cout << "Lista produktow: " << endl;
                bazaDanych.wyswietlListeProduktow();

                int idKupno;
                cout << "Podaj ID produktu do kupna: ";
                cin >> idKupno;

                Produkt* produktDoKupna = bazaDanych.getProdukt(idKupno);
                if (produktDoKupna != nullptr)
                {
                    int ilosc;
                    cout << "Podaj ilosc do kupienia: ";
                    cin >> ilosc;

                    double cena;
                    cout << "Podaj cene: ";
                    cin >> cena;

                    Kupno nowyKupno(produktDoKupna, ilosc, cena);
                    bazaDanych.dodajTransakcje(&nowyKupno);
                }
                else
                {
                    cout << "Nie znaleziono produktu o podanym ID." << endl;
                }
                break;
            }    
       
       
        case 3:
{
    cout << "Wypozyczenie" << endl;
    cout << "Lista produktow: " << endl;
    bazaDanych.wyswietlListeProduktow();

    int idWypozyczenie;
    cout << "Podaj ID produktu do wypozyczenia: ";
    cin >> idWypozyczenie;

    Produkt* produktDoWypozyczenia = bazaDanych.getProdukt(idWypozyczenie);
    if (produktDoWypozyczenia != nullptr)
    {
        int ilosc;
        cout << "Podaj ilosc do wypozyczenia: ";
        cin >> ilosc;

        int dniWypozyczenia;
        cout << "Podaj na ile dni chcesz wypozyczyc: ";
        cin >> dniWypozyczenia;

        double cena;
        cout << "Podaj cene: ";
        cin >> cena;

        Wypozyczenie noweWypozyczenie(produktDoWypozyczenia, ilosc, dniWypozyczenia, cena);
        bazaDanych.dodajTransakcje(&noweWypozyczenie);
    }
    else
    {
        cout << "Nie znaleziono produktu o podanym ID." << endl;
    }
    break;
}
        case 4:
        {
            cout << "Generuj raport" << endl;
            Raport raport(bazaDanych.getTransakcje());
            raport.generujRaport();
            break;
        }

        case 5:
        {
            cout << "Dodaj produkt" << endl;
            cout << "1. Dodaj produkt do kupna" << endl;
            cout << "2. Dodaj produkt do wypozyczenia" << endl;

            int wyborDodaj;
            cout << "Wybierz opcje: ";
            cin >> wyborDodaj;

            string nazwa;
            double cena;
            int ilosc;
            cout << "Podaj nazwe produktu: ";
            cin >> nazwa;
            cout << "Podaj cene produktu: ";
            cin >> cena;
            cout << "Podaj ilosc produktu: ";
            cin >> ilosc;

            Produkt* nowyProdukt = new Produkt(nazwa, cena, ilosc);

            if (wyborDodaj == 1)
            {
                cout << "Dodaj produkt do kupna" << endl;
                bazaDanych.dodajProduktDoKupna(nowyProdukt);
            }
            else if (wyborDodaj == 2)
            {
                cout << "Dodaj produkt do wypozyczenia" << endl;
                bazaDanych.dodajProduktDoWypozyczenia(nowyProdukt);
            }
            else
            {
                cout << "Nieznana opcja." << endl;
            }

            break;
        }

        case 0:
        {
            cout << "Koniec programu." << endl;
            return 0;
        }

        default:
        {
            cout << "Nieznana opcja." << endl;
            break;
        }
    }
}

return 0;
}