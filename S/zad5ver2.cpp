#include <iostream>
using namespace std;



class Element{
    private:

        int v;
        Element* next;
    public:
        Element(int x, Element* next);
        int getValue();
        Element* getNext();
        void setNext(Element* p);
};

class LinkedStack{
    private:
        Element* top;
    public:
        LinkedStack(){top=NULL;};        //tworzy pusty stos
        bool empty();
        void push(int x);  //wstawia daną na stos
        int peek();  
                  //zwraca daną ze stosu
        void pop() {
           if (empty())
           Element* tmp = top;
           top = top->getNext();                    //APROWD
           delete tmp;

    }
















    friend std::ostream& operator<<(std::ostream& out, LinkedStack* s) {
        Element* current = s->top;
        while (current != nullptr) {
            out << current->getValue() << " ";
            current = current->getNext();
        }
        return out;
    }

    ~LinkedStack() {
        while (!empty()) {
            pop();
        }
    }

};
main()
{
    cout<<endl<<"Zadanie 2 - test"<<endl;
    LinkedStack* s = new LinkedStack();
}

