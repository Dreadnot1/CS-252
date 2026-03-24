#include <iostream>
#include <set>
#include <random>
using namespace std;

// constant declarations
const int MIN_NUM = 1, MAX_NUM = 60, LOTTO_BALLS = 7;

// function prototype
set<int> getSet(int);

int main() {
    // declarations
    srand(time(0));
    set<int> intSet = getSet(LOTTO_BALLS);

    // output set in two different ways
    cout << "Requested size: " << LOTTO_BALLS << endl;
    cout << "Set size: " << intSet.size() << endl;
    
    //uses an iterator
    cout << "The set contains: ";
    for (auto it = intSet.begin(); it != intSet.end(); it++) {
        cout << *it << " ";
    } cout << endl;
    
    //uses a RBFL
    cout << "The set contains: ";
    for (auto num: intSet) {
        cout << num << " "; 
    } cout << endl;

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