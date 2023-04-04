#ifndef WYPOZYCZALNIA_H_
#define WYPOZYCZALNIA_H_
#include <iostream>
using namespace std;
class Wypozyczalnia
{

public:
	void menu()
	{
		cout << "\n";
		cout << "Menu" << endl;
		cout << "1. Opis sklepu" << endl;
		cout << "2. Dostepny sprzet" << endl;
		cout << "3. Cennik" << endl;
		cout << "4. Wypozycz sprzet" << endl;
		cout << "5. Zwroc sprzet" << endl;
		cout << "6. Oposc strone" << endl;
		cout << "\n";
	}

	void opis_sklepu()
	{
		fstream opis;
		opis.open("opis_sklepu.txt");
		string linia;
		do
		{
			getline(opis, linia);
			cout << linia << endl;
		}

		while (linia != "");
		opis.close();
	}

	void cennik()
	{
		fstream cennik;
		cennik.open("Cennik.txt");
		string linia;
		do
		{
			getline(cennik, linia);
			cout << linia << endl;
		}

		while (linia != "");
		cennik.close();
	}

	void dostepny_sprzet()
	{
		fstream sprzet;
		sprzet.open(".txt");
		string linia;
		do
		{
			getline(sprzet, linia);
			cout << linia << endl;
		}

		while (linia != "");
		sprzet.close();
	}
};
#endif