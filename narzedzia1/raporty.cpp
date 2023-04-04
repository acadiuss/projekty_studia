<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    // Symulacja odczytu wyników testów uczniów
    vector<double> scores = {6.0, 5.5, 4.5, 3.5, 6.0, 5.0, 4.0, 3.0, 6.0, 5.5};

    // Wyznaczanie średniej ocen
    double average = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();

    // Tworzenie raportu
    time_t now = time(nullptr);
    char date[80];
    strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));
    string filename = date + string("_raport.txt");
    ofstream report(filename);
    if(report.is_open()){
        report << "Raport z dnia " << date << endl;
        report << "Średnia ocen: " << fixed << setprecision(2) << average << endl;
        report.close();
        cout << "Raport zapisany w pliku: " << filename << endl;
    }
    else{
        cerr << "Nie można utworzyć pliku raportu." << endl;
        return -1;
    }

    return 0;
}
=======
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    // Symulacja odczytu wyników testów uczniów
    vector<double> scores = {6.0, 5.5, 4.5, 3.5, 6.0, 5.0, 4.0, 3.0, 6.0, 5.5};

    // Wyznaczanie średniej ocen
    double average = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();

    // Tworzenie raportu
    time_t now = time(nullptr);
    char date[80];
    strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));
    string filename = date + string("_raport.txt");
    ofstream report(filename);
    if(report.is_open()){
        report << "Raport z dnia " << date << endl;
        report << "Średnia ocen: " << fixed << setprecision(2) << average << endl;
        report.close();
        cout << "Raport zapisany w pliku: " << filename << endl;
    }
    else{
        cerr << "Nie można utworzyć pliku raportu." << endl;
        return -1;
    }

    return 0;
}
>>>>>>> 4c6f14fb57814dd263c909c7c1b8f8c5ea64219b
