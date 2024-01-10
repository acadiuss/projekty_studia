#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
    string* t;
    int capacity;
    int size;
public:
    HashTable(int c);                // konstruktor tworzący pustą tablicę o pojemności c
    bool empty();
    int hashFunction(string s);        // funkcja haszująca dla klucza s
    void insert(string s);            // wstawienie klucza s
    void del(string s);                // usuwa element z kluczem s
    string search(string s);        // wyszukuje i zwraca element z s
    friend ostream& operator<<(ostream& out, HashTable& ht); // wypisuje tablicę (z numerami pól), pozostawia puste dla wolnych pól
};

HashTable::HashTable(int c) {
    capacity = c;
    size = 0;
    t = new string[capacity];
}

bool HashTable::empty() {
    return size == 0;
}

int HashTable::hashFunction(string s) {
    int sum = 0;
    for (char ch : s) {
        sum += static_cast<int>(ch);
    }
    cout<<sum%capacity<<endl;
    return sum % capacity;
    
}

void HashTable::insert(string s) {
    int index = hashFunction(s);
    int originalIndex = index;

    while (!t[index].empty()) {
        index = (index + 1) % capacity; // próbkowanie liniowe
        if (index == originalIndex) {
            cout << "Brak miejsca dla klucza: " << s << endl;
            return; // brak miejsca w tablicy
        }
    }

    t[index] = s;
    size++;
}

void HashTable::del(string s) {
    int index = hashFunction(s);
    int originalIndex = index;

    while (!t[index].empty() && t[index] != s) {
        index = (index + 1) % capacity;
        if (index == originalIndex) {
            cout << "Klucz do usunięcia nie istnieje: " << s << endl;
            return; // klucz do usunięcia nie istnieje w tablicy
        }
    }

    if (t[index] == s) {
        t[index] = ""; // usuwamy klucz
        size--;
    }
}

string HashTable::search(string s) {
    int index = hashFunction(s);
    int originalIndex = index;

    while (!t[index].empty() && t[index] != s) {
        index = (index + 1) % capacity;
        if (index == originalIndex) {
            return "Brak klucza: " + s;
        }
    }

    if (t[index] == s) {
        return t[index];
    }

    return "Brak klucza: " + s;
}

ostream& operator<<(ostream& out, HashTable& ht) {
    for (int i = 0; i < ht.capacity; i++) {
        out << "[" << i << "]: " << ht.t[i] << endl;
    }
    return out;
}

int main() {
    // Zadanie 1 - test
    cout << "Zadanie 1 - test" << endl;
    {
        int n = 10; // pojemność tablicy z haszowaniem
        HashTable h(n);
        cout << "empty(): " << h.empty() << endl;

        // Dodajemy element "example"
        h.insert("example");
        cout << "Po dodaniu 'example':\n" << h;

        // Dodajemy element "test"
        h.insert("test");
         h.insert("test");
          h.insert("test");
        cout << "Po dodaniu 'test':\n" << h;

        // Usuwamy element "example"
        h.del("example");
        cout << "Po usunięciu 'example':\n" << h;

        // Szukamy elementu "test"
        cout << "search(\"test\"): " << h.search("test") << endl;

        // Szukamy elementu "example"
        cout << "search(\"example\"): " << h.search("example") << endl;
    }

    return 0;
}
