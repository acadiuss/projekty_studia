#include <iostream>

class Element {
private:
    int value;
    Element* next;

public:
    Element(int x, Element* next = nullptr) : value(x), next(next) {}
    int getValue() { return value; }
    Element* getNext() { return next; }
    void setNext(Element* p) { next = p; }
};

class LinkedStack {
private:
    Element* top;

public:
    LinkedStack() : top(nullptr) {}
    
    bool empty() { return top == nullptr; }

    void push(int x) {
        Element* newElement = new Element(x, top);
        top = newElement;
    }

    int peek() {
        if (empty()) {
            std::cerr << "Error: Stack is empty." << std::endl;
            return -1; // You can choose a different way to handle this error.
        }
        return top->getValue();
    }

    void pop() {
        if (empty()) {
            std::cerr << "Error: Stack is empty." << std::endl;
            return; // You can choose a different way to handle this error.
        }
        Element* temp = top;
        top = top->getNext();
        delete temp;
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

int main() {
    std::cout << "Zadanie 5 - test" << std::endl;
    LinkedStack* s = new LinkedStack();

    // Testowanie operacji stosu
    s->push(1);
    s->push(2);
    s->push(3);

    std::cout << "Stack: " << s << std::endl;
    
    std::cout << "Top element: " << s->peek() << std::endl;

    s->pop();
    s->pop();
    s->push(4);
    s->push(4);
    std::cout << "After popping: " << s << std::endl;

    delete s; // Zwolnienie pamięci

    return 0;
}




//napisz jeszcze raz 