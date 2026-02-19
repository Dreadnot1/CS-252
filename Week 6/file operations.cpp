#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int SIZE = 5;

int main()
{
    //Reading data from a file and storing it in an array
    ifstream fin("file.txt");
    int records[SIZE];
    int i = 0; //counter for while loop
    while (fin >> records[i++]); //compact approach using an extractor
    fin.close();
    
    /*Another approach using a for loop
    for (int i = 0; i < SIZE; i++) {
        fin >> records[i];
    } */
    
    //Writing data to a file using array traversal
    int test[] = {1, 3, 5, 7, 9};
    ofstream fout("out.txt");
    for (int i = 0; i < SIZE; i++) {
        fout << test[i] << endl;
    }
    
    fout.close(); //important to close out files
    
    cout << "OPERATION COMPLETE!\n";
    
    return 0;
}