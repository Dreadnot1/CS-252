#include <iostream>
#include <set>
#include <random>
using namespace std;

// constant declarations
const int MIN_NUM = 300, MAX_NUM = 400,
          MIN_SIZE = 5, MAX_SIZE = 50;

// function prototypes
set<int> getSet(int);

// main function
int main() {
    // declarations
    srand(time(0));
    
    // nr is random size of the set to be generated
    int nr = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;

    // create set
    set<int> intSet = getSet(nr);

    // output set
    cout << "Requested size: " << nr << endl;
    cout << "Set size: " << intSet.size() << endl;
    cout << "The set contains: ";
    for (auto it = intSet.begin(); it != intSet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

// Good practice to include function headers...
// getSet() function returns a STL set of integers
// parameters: n, number of elements to generate
// returns: a STL set of integers
set<int> getSet(int n) {
    // declarations
    set<int> tmpSet;
    int num;

    // generate n random numbers and insert into the set
    while (tmpSet.size() < n) {
        // generate random number MIN_NUM to MAX_NUM
        num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM; 
        // insert number into the set
        tmpSet.insert(num); 
    }

    return tmpSet;
}