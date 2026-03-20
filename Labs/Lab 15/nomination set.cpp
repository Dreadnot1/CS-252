#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main() {
    //Getting ready for file I/O
    ifstream fin("252-demo-set-names.txt");
    ofstream fout("dean-report.txt");
    
    //File header
    fout << "DEAN'S NOMINATION REPORT" << endl;

    //Error checking
    if (!fin) {
        cerr << "Error: could not open 252-demo-set-names.txt" << endl;
        return 1;
    }

    set<string> names_set;
    string temp;

    while (fin >> temp)
        names_set.insert(temp);

    //Writing set to a file
    for (string name : names_set) {
        fout << name << endl;
    }

    fin.close();
    fout.close();

    return 0;
}