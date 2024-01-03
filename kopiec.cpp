#include <iostream>
using namespace std;

class MinHeap 
{
    private:
    int* kopiec;
    int capacity;
    int size;

    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }
    int getParent(int i) { return (i - 1) / 2; }

        public:
    MinHeap(int c) : capacity(c), size(0) {
        kopiec = new int[capacity];
    }

    MinHeap() : capacity(11), size(11) {
        kopiec = new int[capacity]{1, 2, 4, 6, 5, 4, 7, 7, 7, 9, 6};
    }

    ~MinHeap() {
        delete[] kopiec;
    }

    bool empty() { return size == 0; }
    bool full() { return size == capacity; }
    int getSize() { return size; }
    void setSize(int s) { size = s; }
    int getValue(int i) { return kopiec[i]; }
    void setValue(int i, int x) { kopiec[i] = x; }

    void bottomUp(int i) {
        while (i != 0 && kopiec[getParent(i)] > kopiec[i]) {
            swap(kopiec[i], kopiec[getParent(i)]);
            i = getParent(i);
        }
    }

    void topDown(int i) {
        int left = getLeft(i);
        int right = getRight(i);
        int smallest = i;
        if (left < size && kopiec[left] < kopiec[i])
            smallest = left;
        if (right < size && kopiec[right] < kopiec[smallest])
            smallest = right;
        if (smallest != i) {
            swap(kopiec[i], kopiec[smallest]);
            topDown(smallest);
        }
    }
 void insert(int x) {
        if (size == capacity) {
            cout << "Kopiec jest pełny. Nie można wstawić nowego elementu." << endl;
            return;
        }
        size++;
        int i = size - 1;
        kopiec[i] = x;
        bottomUp(i);
    }


    //zad 2

    void deleteMin() {
        if (size == 0) {
            cout << "Kopiec jest pusty. Nie ma czego usuwać." << endl;
            return;
        }
        kopiec[0] = kopiec[size - 1];
        size--;
        topDown(0);
    }

    int minimum() {
        if (size == 0) {
            cout << "Kopiec jest pusty." << endl;
            return INT_MAX; // Wartość oznaczająca brak elementu
        }
        return kopiec[0];
    }

    void del(int i) {
        if (i < 0 || i >= size) {
            cout << "Nieprawidłowy indeks." << endl;
            return;
        }
        kopiec[i] = kopiec[size - 1];
        size--;
        bottomUp(i);
        topDown(i);
    }






    friend ostream& operator<<(ostream& out, MinHeap& h) {
        for (int i = 0; i < h.size; i++)
            out << h.kopiec[i] << " ";
        return out;
    }




    
        };                  
        
        
        void deleteMin(){};                     //usuwa element z minimalną wartością
        int minimum();                        //zwraca minimalną wartość
        void del(int i);                         //usuwa element na pozycji i 


int main() {
    cout << endl << "Zadanie 1 - test" << endl;
    MinHeap h;
    cout << endl << "empty(): 0 - " << h.empty();
    cout << endl << "full(): 0 - " << h.full();
    cout << endl << "Heap before modification: " << h << endl;

    // Test bottomUp
    h.setValue(3, 1); // Zmiana wartości na pozycji 3 na 1
    h.bottomUp(3);    // Przywrócenie własności kopca
    cout << "Heap after bottomUp: " << h << endl;

    // Test topDown
    h.setValue(0, 10); // Zmiana wartości korzenia na 10
    h.topDown(0);      // Przywrócenie własności kopca
    cout << "Heap after topDown: " << h << endl;

    return 0;
}
