#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Wypozyczalnia.h"
#include "Sprzet.h"
using namespace std;

//JAKAŒ STARA KONCEPCJA
/*void dodaj_towar()
{
	string tekst;
	cout << "Podaj nazwe nart: " << endl;
	cin >> tekst;
	ofstream zapis("Cennik.txt", ios_base::app);
	zapis << tekst;
	zapis.close(); //obowi¹zkowo nale¿y zamkn¹æ plik
}*/

int main()
{
	/* UTWORZENIE OBIEKTOW DLA NASZEGO SPRZETU */
	Narty narty;
	narty.wypelnij();
	Buty buty;
	buty.wypelnij();
	Snowboard snowboard;
	snowboard.wypelnij();
	Wypozyczalnia sklep;
	/* UTWORZENIE OBIEKTOW DLA NASZEGO SPRZETU */

	int wybor;
	for (;;)
	{
		sklep.menu();
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{
		case 1:
			sklep.opis_sklepu();
			break;

		case 2:
			cout << "Narty:" << endl;
			narty.wyswietl_wszystkie();
			cout << endl << "Buty:" << endl;
			buty.wyswietl_wszystkie();
			cout << endl << "Snowboard:" << endl;
			snowboard.wyswietl_wszystkie();
			break;
		case 3:
			sklep.cennik();
			break;

		case 4:
			int wyb;
			cout << "1. Narty\n2. Buty\n3. Snowboard\n";
			cin >> wyb;
			switch (wyb)
			{
			case 1:
				narty.wyswietl_wszystkie();
				break;
			case 2:
				buty.wyswietl_wszystkie();
				break;
			case 3:
				snowboard.wyswietl_wszystkie();
				break;

			}

			break;
		case 5:
			narty.wypozycz(2);
			break;
		case 6:
			cout << "Dziekujemy za odwiedzenie naszej strony i zapraszamy ponownie" << endl;
			exit(0);
			break;

		default: cout << "Przykro nam ale wybrana opcja nie istnieje" << endl;
			break;
		}
	}
	return 0;
}