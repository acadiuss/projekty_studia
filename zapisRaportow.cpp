#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

class Report {
    private:
        time_t test_time;
        string test_name;
        string data;

    public:
        Report(string name, string d) {
            test_name = name;
            data = d;
            test_time = time(0); // pobranie aktualnego czasu
        }

        void save(string folder) {
            string filename = folder + "/" + test_name + ".txt";
            ofstream file(filename);
            if (file.is_open()) {
                file << "Test name: " << test_name << endl;
                file << "Test time: " << ctime(&test_time); // zamiana czasu na tekst
                file << "Data: " << data << endl;
                file.close();
                cout << "Report saved to " << filename << endl;
            } else {
                cout << "Error opening file " << filename << endl;
            }
        }
};

int main() {
    string test_name, data, folder;
    cout << "Enter test name: ";
    getline(cin, test_name);
    cout << "Enter data: ";
    getline(cin, data);
    cout << "Enter folder path: ";
    getline(cin, folder);

    Report report(test_name, data);
    report.save(folder);

    return 0;
}
