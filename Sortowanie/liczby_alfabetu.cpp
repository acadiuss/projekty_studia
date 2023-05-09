#include <iostream>
#include <string>

using namespace std;

void generateCombinations(int n, string current) 
{
    if (n == 0) {
        cout << current << endl;
    } else { 
        for (char letter = 'a'; letter <= 'z'; letter++) {
            string newCurrent = current + letter ;
            generateCombinations(n - 1, newCurrent);
        }
    }
}

int main() 
{
    int length = 26; // długość kombinacji
    generateCombinations(length, "");
    system("pause");
    return 0;
}



/// przesunie cie o jedem bit w prawo kop>>=1; dzielenie przez 2 , przez 4  ect.   NOTATKI Z POPRZEDNICH ZAJEC ...









///k elementowe zbiory n elementowych podzbiorów
/// ald abcd... jedna pzycja binarna  unssingt (1bit) long long    2 dzo 8 , na 8 bitach tyle moge zapisac
///a-h wszystkie 8 bitowe liczby 

/// dla 26 liter wszystkie mozliwe kombinacje 2^26
