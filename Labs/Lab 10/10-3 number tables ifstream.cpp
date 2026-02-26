//LAB 10-3
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int LINES = 100, COLUMNS = 10, WIDTH = 6;

//Function prototypes
int calc_avg(int, int);

int main() {
    string input_file = "252-lab-10-3-files-input.txt";
    int numbers[100] = {0};
    int sum, avg;
    
    //Getting the file input
    ifstream fin(input_file);
    
    //Loops through the file and stores data in an array
    for (int i = 0; i < LINES; i++) {
        fin >> numbers[i];
        sum += numbers[i];
    }
    
    //Closes the file
    fin.close();
    
    //Calls the function
    avg = calc_avg(sum, LINES);
    
    //Displays the required variables
    for (int i = 0; i < LINES; i++) {
        cout << setw(WIDTH) << numbers[i];
        if ((i+1) % COLUMNS == 0) {
            cout << endl;
        }
    }
    cout << "The sum is: " << sum << endl;
    cout << "The average is: " << avg;

    return 0;
}

//Declares a function for calculating the average
int calc_avg(int sum, int lines) {
    return sum / lines;
}