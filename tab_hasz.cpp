#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
    string* t;
    int capacity;
    int size;
public:

    HashTable(int c)// konstruktor tworzący pustą tablicę o pojemności c
    {
        capacity=c;
        size=0;
        t=new string[capacity];
    }
    
    bool empty()
    {   
        return size ==0;
    }
    int full()
    {
        return size==capacity;
    }
    int hashFunction(string s)        // funkcja haszująca dla klucza s
    {
    int sum =0;
    for (char ch :s)
    {
        sum+=static_cast<int>(ch);
    }
    return sum%capacity;
    }
    
void insert(string s) {
    int index = hashFunction(s);
    int originalIndex = index;

    while (!t[index].empty()) {
        index = (index + 1) % capacity;
        if (index == originalIndex) {
            cout << "brak miejsca w tablicy dla klucza: " << s << endl;
            return;
        }
    }

    t[index] = s;
    size++;
}

void del(string s) {
    int index = hashFunction(s);
    int originalIndex = index;

    while (!t[index].empty() && t[index] != s) {
        index = (index + 1) % capacity;
        if (index == originalIndex) {
            cout << "klucz do usunięcia nie istnieje: " << s << endl;
            return;
        }
    }

    if (t[index] == s) {
        t[index] = "";
        size--;
    }
}

string search(string s) {
    int index = hashFunction(s);
    int originalIndex = index;

    while (!t[index].empty() && t[index] != s) {
        index = (index + 1) % capacity;
        if (index == originalIndex) {
            return "Brak klucza " + s;
        }
    }

    if (t[index] == s) {
        return t[index];
    } else {
        return "brak kluc za " + s;
    }
}

    
    friend ostream& operator<<(ostream& out, HashTable& ht) // wypisuje tablicę (z numerami pól), pozostawia puste dla wolnych pól
    {    for (int i = 0; i < ht.capacity; i++) {
        out << "[" << i << "]: " << ht.t[i] << endl;
    }
    return out;
    }
    
};


int main() {
    cout << "Zadanie 2 - test" << endl;
    {
        int n = 40; // Początkowa pojemność tablicy z haszowaniem
        HashTable h(n);

        // Inicjalizacja danych do testowania
        string dane[] = {"Julia", "Zuzanna", "Zofia", "Lena", "Maja", "Hanna", "Amelia", "Alicja", "Maria", "Aleksandra",
                         "Oliwia", "Natalia", "Wiktoria", "Emilia", "Antonina", "Laura", "Pola", "Iga", "Anna", "Liliana",
                         "Antoni", "Jakub", "Jan", "Szymon", "Franciszek", "Filip", "Aleksander", "Mikolaj", "Wojciech",
                         "Kacper", "Adam", "Michal", "Marcel", "Stanislaw", "Wiktor", "Piotr", "Igor", "Leon", "Nikodem",
                         "Mateusz"};

        for (const auto& key : dane) {
            h.insert(key);
        }

        // Wyświetlenie tablicy po wstawieniu danych
        cout << h;

        // Test wyszukiwania dla kilku kluczy
        cout << "search(\"Julia\"): " << h.search("Julia") << endl;
        cout << "search(\"Adam\"): " << h.search("Adam") << endl;
        cout << "search(\"Zofia\"): " << h.search("Zofia") << endl;

        // Test usunięcia kilku kluczy
        h.del("Lena");
        h.del("Szymon");
        h.del("Antoni");
        
        // Wyświetlenie tablicy po usunięciu danych
        cout << "Po usunięciu kilku kluczy:\n" << h;
    }

    return 0;
}

