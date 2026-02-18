#include <iostream>
using namespace std;

const int ARRAY_SIZE = 5;

int main() {
    //Arrays: container, simplest type of data structure, size is declared
    int values[ARRAY_SIZE] = {100, 105, 110, 115, 120};
    int sum = 0; //accumulator
    int doubled = 0;
    
    for (int val: values) { //range-based for loop for array traversal
        sum += val;
    }
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        values[i] *= 2;
    }
    
    for (auto val : values) {
        cout << val << " ";
    }
    
    cout << "The sum of the array is: " << sum;
    
    //Vectors: simple container, flexible sizing

    return 0;
}