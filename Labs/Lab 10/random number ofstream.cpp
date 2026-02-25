//Lab 10-1
#include <iostream>
#include <fstream>
using namespace std;

const int NUMBERS = 5000, MIN = 1, MAX = 7, NLINE = 80;

int main()
{
    //Setup
    srand(time(0));
    int number;
    
    //Creates or overwrites an output file
    ofstream fout("252-lab-10-2-output.txt");
    
    //Outputs 5000 random numbers to the console and output file simulatenously
    for (int i = 0; i < NUMBERS; i++) {
        number = rand() % (MAX-MIN+1) + MIN;
        fout << number;
        cout << number;
        if ((i+1) % NLINE == 0) {
            fout << endl;
            cout << endl;
        }
    }
    
    //Closes out the output file
    fout.close();

    return 0;
}