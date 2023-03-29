#include <fstream>
#include <iostream>

int main() {
    std::ofstream plik;
    plik.open("/ścieżka/do/folderu/raport.txt");
    
    if(plik.is_open()) {
        plik << "To jest przykładowy raport.";
        plik.close();
        std::cout << "Raport został zapisany w wybranym folderze." << std::endl;
    } else {
        std::cout << "Nie udało się otworzyć pliku!" << std::endl;
    }
    
    return 0;
}