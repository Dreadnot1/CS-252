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
    
    vector<int> evens = getParityVector(SIZE, even);
    vector<int> odds = getParityVector(SIZE, odd);
    
    print_vector(evens, even);
    cout << endl;
    print_vector(odds, odd);
    
    cout << endl;
    validate_vector(evens, even);
    validate_vector(odds, odd);

    return 0;
}

//Creates an int vector and fills it with random odd or even nums
vector<int> getParityVector(int size, int parity) {
    vector<int> random_ints;
    int random;
    
    while (random_ints.size() < size) {
        random = rand() % (MAX - MIN + 1) + MIN;
        
        if (parity == 0) {
            if (random % 2 == 0) {
                random_ints.push_back(random);
            } else {
                continue;
            }
        } else if (parity == 1) {
            if (random % 2 == 1) {
                random_ints.push_back(random);
            } else {
                continue;
            }
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
    bool is_validated;
    int parity_check = 0;
    
    //checks first for even parity
    if (parity == 0) {
        for (auto num : numbers) {
            if (num % 2 == 0) {
                parity_check++;
            } else {
                parity_check--;
            }
        }       
    } else {
        for (auto num : numbers) {
            if (num % 2 == 1) {
                parity_check++;
            } else {
                parity_check--;
            }
        }           
    }
    
    if (parity_check == numbers.size()) {
        is_validated = true;
        cout << "Vector check: " << "PASS" << endl;
    } else {
        is_validated = false;
        cout << "Vector check: " << "FAIL" << endl;
    }
    return is_validated;
}