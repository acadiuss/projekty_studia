<<<<<<< HEAD
#include<iostream>
using namespace std; 

class Samochod
{
public:
float waga;
string marka;
int moc;
int max_predkosc;

void add_car()
{
    cout<<"DODAWANIE NOWEGO SAMOCHODU DO BAZY :  "<< endl;
    cout<<"Podaj marke : ";
    cin>>marka;
    cout<<"Podaj wage : ";
    cin>>waga;
    cout<<"Podaj max predkosc : ";
    cin>>max_predkosc;
}

};

int main()
{
    Samochod s1;
    Samochod s2;
    s1.add_car();
    s2.add_car();


    return 0;

=======
#include<iostream>
using namespace std; 

class Samochod
{
public:
float waga;
string marka;
int moc;
int max_predkosc;

void add_car()
{
    cout<<"DODAWANIE NOWEGO SAMOCHODU DO BAZY :  "<< endl;
    cout<<"Podaj marke : ";
    cin>>marka;
    cout<<"Podaj wage : ";
    cin>>waga;
    cout<<"Podaj max predkosc : ";
    cin>>max_predkosc;
}

};

int main()
{
    Samochod s1;
    Samochod s2;
    s1.add_car();
    s2.add_car();


    return 0;

>>>>>>> 4c6f14fb57814dd263c909c7c1b8f8c5ea64219b
}