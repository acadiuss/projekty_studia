#include <iostream>

int binarySearch1(int* S, int n, int x) {
    int left = 0;        // Lewy wskaźnik początkowy
    int right = n - 1;   // Prawy wskaźnik początkowy

    while (left <= right) {
        int mid = left + (right - left) / 2; //  środkowy indeks

        if (S[mid] == x) {
            return mid; // Znaleziono x, zwróć indeks
        }

        if (S[mid] < x) {
            left = mid + 1; // Szukaj w prawej połowie
        } else {
            right = mid - 1; // Szukaj w lewej połowie
        }
    }

    return -1; //brak x w tab
}

int main() {
    std::cout << "Zadanie 2 - test" << std::endl;

    int n = 20;  // Przykładowy rozmiar
    int* S = new int[n]{/* dane do testowania */};
    int x;  // Wartość do wyszukania

    // Wczytaj/ustaw x dla przypadku 1
    std::cout << "Przypadek 1: x znalezione w pierwszym kroku (pozycja ...) " << binarySearch1(S, n, x) << std::endl;

    return 0;
}
