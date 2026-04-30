#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //Creating a vector to store data from a file
    vector<string> clients;
    ifstream fin("clients.txt");
    string line;
    
    //Reads data from the file and closes it
    while (getline(fin, line)) {
        clients.push_back(line);
    }
    fin.close();

    //Alphabetizes the vector
    sort(clients.begin(), clients.end());
    
    //Traverses the vector and writes the data to console & file
    ofstream fout("output.txt");
    cout << "Client List:\n";
    fout << "Client List:\n";
    for (int i = 0; i < clients.size(); i++) {
        cout << "\t" << clients[i] << endl;
        fout << "\t" << clients[i] << endl;
    }
    fout.close();

    return 0;
}