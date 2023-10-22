#include <iostream>

using namespace std;

void print(int* S, int n) {
    for (int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}

int linearSearch1(int* S, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (S[i] == x) {
            return i;  // Znaleziono x, zwracamy indeks pierwszego wystąpienia.
        }
    }
    return -1; 
}

int main() {
    cout << "Zadanie 1 - test" << endl;
    int n = 20;
    int* S = new int[n]; 
    int x;
    cout<<endl<<"Przypadek 1: x na pozycji 0 : "<<linearSearch1(S,n,x);  //x na pozycji 0
}