#include <iostream>
#include <map>
#include <string>
#include <ctime>

using namespace std;

// Funkcja do generowania aktualnej daty i godziny w formacie "YYYY-MM-DD HH:MM:SS"
string getCurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return buf;
}

// Klasa reprezentująca pojedynczy produkt w magazynie
class Product {
private:
    string name;
    int quantity;

public:
    Product(string name, int quantity) {
        this->name = name;
        this->quantity = quantity;
    }

    void addQuantity(int quantity) {
        this->quantity += quantity;
    }

    void removeQuantity(int quantity) {
        if (this->quantity < quantity) {
            throw "Nie wystarczająca ilość produktów w magazynie";
        }
        this->quantity -= quantity;
    }

    string getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }
};

// Klasa reprezentująca magazyn, przechowująca produkty i is  ch stany
class Warehouse {
private:
    map<string, Product*> products;

public:
    void addProduct(string name, int quantity) {
        if (products.count(name)) {
            products[name]->addQuantity(quantity);
        } else {
            products[name] = new Product(name, quantity);
        }
    }

    void removeProduct(string name, int quantity) {
        if (products.count(name)) {
            products[name]->removeQuantity(quantity);
        } else {
            throw "Produkt nie istnieje w magazynie";
        }
    }

    void printInventoryReport() {
        cout << "Raport z magazynu wygenerowany o " << getCurrentDateTime() << endl;
        cout << "----------------------------------------------" << endl;
        for (auto const& [name, product] : products) {
            cout << product->getName() << ": " << product->getQuantity() << endl;
        }
        cout << "----------------------------------------------" << endl;
    }
};

int main() {
    Warehouse warehouse;

    // Przyjmowanie towarów do magazynu
    warehouse.addProduct("Mleko", 10);
    warehouse.addProduct("Chleb", 20);
    warehouse.addProduct("Jogurt", 5);
    warehouse.addProduct("Kielbasa", 20);
    warehouse.addProduct("Agrest", 20);
    warehouse.addProduct("Jagody", 20);
    warehouse.addProduct("Papryka", 20);

    // Wydawanie towarów z magazynu
    warehouse.removeProduct("Mleko", 5);

    // Generowanie raportu o stanie magazynu
    warehouse.printInventoryReport();

    return 0;
}
    