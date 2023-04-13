#ifndef SPRZET_H_
#define SPRZET_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
class Sprzet
{
protected:
	string marka, rozmiar;
	int dostepny, id;
	int ilosc_obiektow2;
	string** dane2;

public:
	void zczytaj(int xx) {
		int x;
		x = xx;
		fstream opis;
		switch (x)
		{
		case 1:
			opis.open("narty.txt");
			break;
		case 2:
			opis.open("buty.txt");
			break;
		case 3:
			opis.open("snowboard.txt");
			break;
		}
		string linia;
		int nr_argumentow = 0; //zmienna pomocnicza tablicy danych
		int nr_obiektow = 0; //zmienna pomocnicza tablicy danych
		int dlugosc_txt = 0;
		// sprawdzanie dlugosci pliku tekstowego
		do
		{
			getline(opis, linia);
			dlugosc_txt++;
		} while (linia != "stop");
		//obliczanie ilosci obiektow do utworzenia, na jeden obiekt rzypada 5 linijek tekstu w pliku narty.txt
		int ilosc_obiektow = (dlugosc_txt / 4);
		string** dane; // tablica na pobrane dane z pliku narty.txt
		dane = new string * [(ilosc_obiektow)];
		for (int i = 0; i < (ilosc_obiektow); i++)
		{
			dane[i] = new string[4];
		}
		opis.seekg(0);
		//pobieranie danych z pliku txt
		do
		{
			getline(opis, linia);
			dane[nr_obiektow][nr_argumentow++] = linia;
			if (linia == "")
			{
				nr_argumentow = 0;
				nr_obiektow++;
			}
		} while (linia != "stop");
		opis.close();

		dane2 = dane;
		ilosc_obiektow2 = ilosc_obiektow;
	}
	void wypozycz2(int id, int xx, int dost)
	{
		int x;
		x = xx;
		fstream opis;
		switch (x)
		{
		case 1:
			opis.open("narty.txt");
			break;
		case 2:
			opis.open("buty.txt");
			break;
		case 3:
			opis.open("snowboard.txt");
			break;
		}

		string linia;
		int nr_argumentow = 0; //zmienna pomocnicza tablicy danych
		int nr_obiektow = 0; //zmienna pomocnicza tablicy danych
		int dlugosc_txt = 0;
		// sprawdzanie dlugosci pliku tekstowego



		do
		{
			getline(opis, linia);
			dlugosc_txt++;
		} while (linia != "stop");
		//obliczanie ilosci obiektow do utworzenia, na jeden obiekt rzypada 5 linijek tekstu w pliku narty.txt
		int ilosc_obiektow = (dlugosc_txt / 4);

		int dokiedy = ((id + 1) * 4) - 1;

		string* dane = new string[(ilosc_obiektow * 4)];


		opis.seekg(0);
		//pobieranie danych z pliku txt
		int nrlini = 0;
		for (int i = 0; i < ilosc_obiektow * 4; i++)
		{
			getline(opis, linia);
			if (nrlini == dokiedy - 1)
			{
				dane[i] = to_string(dost - 1);
			}
			else {
				dane[i] = linia;
			}


			nrlini++;



		}
		opis.seekg(0);

		ofstream zapis("narty.txt");
		for (int i = 0; i < ilosc_obiektow * 4; i++)
		{
			//cout<< dane[i] << endl;
			zapis << dane[i] << endl;
		}

		zapis.close(); //obowi¹zkowo nale¿y zamkn¹æ plik


	}
};


class Narty : public Sprzet
{
	Narty** tab;
public:
	Narty() {};
	Narty(string m, string r, int d, int id)
	{
		marka = m;
		rozmiar = r;
		dostepny = d;
		id = id;
	}

	void wypelnij()
	{
		zczytaj(1);

		// tablica wskaznikow na nasze wszystkie narty z pliku txt
		tab = new Narty * [(ilosc_obiektow2)];
		// tworzenie obiektow dla naszych nart oraz uzupelnianie je danymi pobranymi z pliku txt
		int id = 0;
		for (int i = 0; i < ilosc_obiektow2; i++)
		{
			id = i;
			tab[i] = new Narty(dane2[i][0], dane2[i][1], stoi(dane2[i][2]), id);
		}
	}

	void wyswietl()
	{
		cout << marka << " " << " " << rozmiar << " " << dostepny << endl;
	}
	void wyswietl_wszystkie()
	{
		for (int i = 0; i < ilosc_obiektow2; i++)
		{
			if (tab[i]->dostepny > 0)
			{
				cout << tab[i]->marka << " " << tab[i]->rozmiar << " Ilosc: " << tab[i]->dostepny << endl;
			}
		}
	}
	void wypozycz(int id)
	{
		wypozycz2(id, 1, Narty::tab[id]->dostepny);
		Narty::tab[id]->dostepny--;
	}


};


class Buty : public Sprzet
{
	Buty** tab;
public:
	Buty() {};
	Buty(string m, string r, int d, int id)
	{
		marka = m;
		rozmiar = r;
		dostepny = d;
		id = id;
	}

	void wypelnij()
	{
		zczytaj(2);
		tab = new Buty * [(ilosc_obiektow2)];
		// tworzenie obiektow dla naszych nart oraz uzupelnianie je danymi pobranymi z pliku txt
		int id = 0;
		for (int i = 0; i < ilosc_obiektow2; i++)
		{
			id = i;
			tab[i] = new Buty(dane2[i][0], dane2[i][1], stoi(dane2[i][2]), id);
		}
	}

	void wyswietl()
	{
		cout << marka << " " << " " << rozmiar << " " << dostepny << endl;
	}
	void wyswietl_wszystkie()
	{
		for (int i = 0; i < ilosc_obiektow2; i++)
		{
			if (tab[i]->dostepny > 0)
			{
				cout << tab[i]->marka << " " << tab[i]->rozmiar << " Ilosc: " << tab[i]->dostepny << endl;
			}
		}
	}
	void wypozycz(int id)
	{
		wypozycz2(id, 2, Buty::tab[id]->dostepny);
		Buty::tab[id]->dostepny--;
	}
};

class Snowboard : public Sprzet
{
	Snowboard** tab;
public:
	Snowboard() {};
	Snowboard(string m, string r, int d, int id)
	{
		marka = m;
		rozmiar = r;
		dostepny = d;
		id = id;
	}

	void wypelnij()
	{
		zczytaj(3);

		tab = new Snowboard * [(ilosc_obiektow2)];
		// tworzenie obiektow dla naszych nart oraz uzupelnianie je danymi pobranymi z pliku txt
		int id = 0;
		for (int i = 0; i < ilosc_obiektow2; i++)
		{
			id = i;
			tab[i] = new Snowboard(dane2[i][0], dane2[i][1], stoi(dane2[i][2]), id);
		}
	}

	void wyswietl()
	{
		cout << marka << " " << " " << rozmiar << " " << dostepny << endl;
	}
	void wyswietl_wszystkie()
	{
		for (int i = 0; i < ilosc_obiektow2; i++)
		{
			if (tab[i]->dostepny > 0)
			{
				cout << tab[i]->marka << " " << tab[i]->rozmiar << " Ilosc: " << tab[i]->dostepny << endl;
			}
		}
	}
	void wypozycz(int id)
	{
		wypozycz2(id, 2, Snowboard::tab[id]->dostepny);
		Snowboard::tab[id]->dostepny--;
	}
};

#endif