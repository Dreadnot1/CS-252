#include <iostream>
using namespace std;

//Why are functions so useful?
//Code reuse, modularity, repeatibility, performs tasks and algorithms

//Functions should do one thing, and do it well.
//This is known as the Single Responsibility Principle.

//Function prototype
int find_max(int, int, int);

int main() {
    int value1 = 100323, value2 = 203, value3 = 3992;
    
    //Function call
    int max = find_max(value1, value2, value3);
    
    //Displays the numbers and the final result
    cout << "The three numbers given are: "
         << value1 << ", "
         << value2 << ", "
         << value3 << endl;
    cout << "The maximum number is: " << max;

    return 0;
}

//Function definition
int find_max(int val1, int val2, int val3) {
    if (val1 > val2 && val1 > val3) {
        return val1;
    } else if (val2 > val1 && val2 > val3) {
        return val2;
    } else {
        return val3;
    }
}