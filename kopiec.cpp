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

/*version 2.0: #include <iostream>
#include <ostream>

class MinHeap {
    private:
        int* kopiec;
        int capacity;
        int size;
    public:
        MinHeap(int c);            //tworzy pusty kopiec o pojemności c
        MinHeap();                //konstruktor do testów kopca - należy utworzyć kopiec z następującą zawartością: 1, 2, 4, 6, 5, 4, 7, 7, 7, 9, 6
        bool empty();
        bool full();
        int getLeft(int i);                    //zwraca pozycję lewego syna
        int getRight(int i);                //zwraca pozycję prawego syna
        int getParent(int i);                //zwraca pozycję ojca
        int getSize();                        //zwraca rozmiar kopca
        void setSize(int s);                //ustawia rozmiar kopca na s
        int getValue(int i);                //zwraca wartość z pozycji i
        void setValue(int i, int x);        //ustawia wartość x na pozycji i
        void bottomUp(int i);                //przywraca własność kopca metodą wynurzania
        void topDown(int i);                //przywraca własność kopca metodą zatapiania
        friend std::ostream& operator<<(std::ostream& out, MinHeap& h);
};

MinHeap::MinHeap(int c) {
    capacity = c;
    kopiec = new int[capacity];
    size = 0;
}

MinHeap::MinHeap() {
    capacity = 11;
    kopiec = new int[capacity]{1, 2, 4, 6, 5, 4, 7, 7, 7, 9, 6};
    size = capacity;
}

bool MinHeap::empty() {
    return size == 0;
}

bool MinHeap::full() {
    return size == capacity;
}

int MinHeap::getLeft(int i) {
    if (2 * i + 1 < size) {
        return 2 * i + 1;
    } else {
        return -1; // lub inny sposób obsługi przypadku
    }
}

int MinHeap::getRight(int i) {
    if (2 * i + 2 < size) {
        return 2 * i + 2;
    } else {
        return -1; // lub inny sposób obsługi przypadku
    }
}

int MinHeap::getParent(int i) {
    if (i == 0) {
        return -1; // -1 nie reprezentuje indeksu tablicy
    } else {
        return (i - 1) / 2;
    }
}

int MinHeap::getSize() {
    return size;
}

void MinHeap::setSize(int s) {
    size = s;
}

int MinHeap::getValue(int i) {
    return kopiec[i];
}

void MinHeap::setValue(int i, int x) {
    kopiec[i] = x;
}

void MinHeap::bottomUp(int i) 
{
    if(i<=0)
    {
        return;//dla jedno elementowego ,kopiec jest posortowany
    }
    int parent=getParent(i);

    if(kopiec[i]>kopiec[parent])
    {
        if (kopiec[i] > kopiec[parent]) 
        {
        // Jeśli wartość węzła jest większa niż jego rodzica, zamień je miejscami
        std::swap(kopiec[i], kopiec[parent]);
        bottomUp(parent);  // Rekurencyjnie kontynuuj przywracanie dla rodzica
        }
        
    }
}

void MinHeap::topDown(int i) 
{
   int l = getLeft(i);
    int r = getRight(i);
    int g = i;

    if (l != -1 && kopiec[l] > kopiec[i]) {
        g = l;
    }

    if (r != -1 && kopiec[r] > kopiec[g]) {
        g = r;
    }

    if (g != i) {
        std::swap(kopiec[i], kopiec[g]);
        bottomUp(g);
    }  
}

std::ostream& operator<<(std::ostream& out, MinHeap& h) {
    for (int i = 0; i < h.getSize(); i++) {
        out << h.getValue(i) << " ";
    }
    return out;
}

int main() {
    // Zadanie 1 - test
    std::cout << std::endl << "Zadanie 1 - test" << std::endl;
    MinHeap h;
    std::cout << std::endl << "Kopiec przed operacją topDown: " << h;

    // Test topDown
    std::cout << std::endl << "Test topDown:" << std::endl;
    h.topDown(0);

    // Wyświetl kopiec po zastosowaniu topDown
    std::cout << std::endl << "Kopiec po operacji topDown: " << h;

    // Test bottomUp
    std::cout << std::endl << "Test bottomUp:" << std::endl;
    h.bottomUp(9);  // Przywracanie dla ostatniego elementu
    std::cout << std::endl << "Kopiec po operacji bottomUp: " << h;

    return 0;
}
*/
kopiec versia 3
/*#include <iostream>
#include <algorithm>

class MinHeap
{
private:
    int* kopiec;
    int capacity;
    int size;

public:
    MinHeap(int c) : capacity(c), size(0)    // Initialize members in the constructor initializer list
    {
        kopiec = new int[capacity];
    }

    MinHeap() : MinHeap(11)  // Delegate to the parameterized constructor with a default capacity of 11
    {
        std::copy_n(new int[capacity]{1, 2, 4, 6, 5, 4, 7, 7, 7, 9, 6}, capacity, kopiec);
        size = capacity;
    }

    bool empty()
    {
        return size == 0;
    }

    bool full()
    {
        return size == capacity;
    }

    int getLeft(int i)
    {
        if (2 * i + 1 < size)
        {
            return 2 * i + 1;
        }
        else
        {
            return -1;
        }
    }

    int getRight(int i)
    {
        if (2 * i + 2 < size) // Removed semicolon after size
        {
            return 2 * i + 2;
        }
        else
        {
            return -1;
        }
    }

    int getParent(int i)
    {
        if (i == 0)
        {
            return -1;
        }
        else
        {
            return (i - 1) / 2; // Corrected variable name from 'n' to 'i'
        }
    }

    int getSize()
    {
        return size;
    }

    void setSize(int s)
    {
        size = s;
    }

    int getValue(int i)
    {
        return kopiec[i];
    }

    void setValue(int i, int x)
    {
        kopiec[i] = x;
    }

    void bottomUp(int n)
    {
        if (n > 0)
        {
            int p = getParent(n);

            if (kopiec[n] > kopiec[p])
            {
                std::swap(kopiec[n], kopiec[p]);
                bottomUp(p);
            }
        }
    }

    void topDown(int n)
    {
        int l = getLeft(n);
        int r = getRight(n); // Corrected variable name from 'p' to 'r'
        int g = n;

        if (l != -1 && kopiec[l] > kopiec[n])
        {
            g = l;
        }

        if (r != -1 && kopiec[r] > kopiec[g]) // Corrected variable name from 'p' to 'r'
        {
            g = r;
        }

        if (g != n)
        {
            std::swap(kopiec[n], kopiec[g]);
            topDown(g);
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const MinHeap& h);
};

std::ostream& operator<<(std::ostream& out, const MinHeap& h)
{
    for (int i = 0; i < h.size; ++i)
    {
        out << h.kopiec[i] << " ";
    }
    return out;
}

int main()
{   
    // Zadanie 1 - test
    std::cout << std::endl << "Zadanie 1 - test" << std::endl;
    MinHeap h;
    std::cout << std::endl << "empty(): " << h.empty();
    std::cout << std::endl << "full(): " << h.full();

    // Test bottomUp and topDown
    std::cout << std::endl << "Test bottomUp and topDown:" << std::endl;

    // Modify the value at a specific position to violate the heap property
    int positionToModify = 2;  // Choose the position to modify
    int newValue = 8;          // Choose a new value
    h.setValue(positionToModify, newValue);

    // Display the heap before applying operations
    std::cout << std::endl << "Kopiec przed operacją topDown/bottomUp: " << h;

    // Test topDown
    std::cout << std::endl << "Test topDown:" << std::endl;
    h.topDown(0);

    // Display the heap after applying topDown
    std::cout << std::endl << "Kopiec po operacji topDown: " << h;

    // Test bottomUp
    std::cout << std::endl << "Test bottomUp:" << std::endl;
    h.bottomUp(positionToModify);  // Restoring heap property for the modified position
    std::cout << std::endl << "Kopiec po operacji bottomUp: " << h;

    // Display the final state of the heap
    std::cout << std::endl << "Final state of the heap: " << h;
    
    return 0;
}
*/
