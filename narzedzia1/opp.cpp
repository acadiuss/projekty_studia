#include <iostream>
using namespace std;

class Zwierze
{
    public:
///atrybuty
string gatunek;
string imie;
int wiek;

///funkcjie,metody
///wczytywanie danych 

void dodaj_zwierze()
{
    cout<<"DODAWANIE NOWEGO ZWIERZECIA DO BAZY :  "<< endl;
    cout<<"Podaj gatunek : ";
    cin>>gatunek;
    cout<<"Podaj imie : ";
    cin>>imie;
    cout<<"Podaj wiek : ";
    cin>>wiek;
} 

//metoda daj glos
void daj_glos()
{
 if (gatunek=="kot") cout<< imie <<" lat"<<wiek<<" : Mial!";
 else if (gatunek=="koza") cout<< imie <<" lat"<<wiek<<" : beee!";
 else if (gatunek=="krowa") cout<< imie <<" lat"<<wiek<<" : muu!";
 else cout<<"Nienzany gatunek";
}



};


int main()
{
///tworze obiekt z1 
///3 szufladki pamieci i 2 metody
///  z1.gatunek  z2.gatunek
/// mogé tworzyc tablice obiektów


    Zwierze z1; 
    z1.dodaj_zwierze();
    z1.daj_glos();


    Zwierze z2;

    


    return 0;

}
