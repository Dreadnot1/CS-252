#include <iostream>
#include <vector>
#include <random>
using namespace std;

//constants
const int MAX = 9999, MIN = 1000, SIZE = 10;

//prototypes
vector<int> getParityVector(int size, int parity);
void print_vector(vector<int> numbers, int parity);
bool validate_vector(vector<int> numbers, int parity);

int main()
{
    //random seed
    srand(time(0));
    int even = 0, odd = 1;
    bool status;
    
    vector<int> evens = getParityVector(SIZE, even);
    vector<int> odds = getParityVector(SIZE, odd);
    
    // populating the vectors
    print_vector(evens, even);
    cout << endl;
    print_vector(odds, odd);
    
    // validating the even vector
    cout << endl;
    status = validate_vector(evens, even);
    cout << (status ? "PASS" : "FAIL");

    // validating the odd vector
    cout << endl;
    status = validate_vector(odds, odd);
    cout << (status ? "PASS" : "FAIL");

    return 0;
}

//Creates an int vector and fills it with random odd or even nums
vector<int> getParityVector(int size, int parity) {
    vector<int> random_ints;
    int random;
    
    while (random_ints.size() < size) {
        random = rand() % (MAX - MIN + 1) + MIN;

        // parity determines whether vector is filled with odds or evens
        // 0 adds evens, 1 adds odds
        if (random % 2 == parity) {
            random_ints.push_back(random);
        }
    }
    return random_ints;
}

//Prints out the contents of a vector
void print_vector(vector<int> numbers, int parity) {
    if (parity == 0) {
        cout << "Even: ";
    } else {
        cout << "Odd: ";
    }
    for (auto num : numbers) {
        cout << num << " ";
    }
}

//Checks if a vector contains all even or all odd numbers
bool validate_vector(vector<int> numbers, int parity) {
    for (auto num : numbers) {
        if (num % 2 != parity) {
            return false;
        }
    }
    return true;
}