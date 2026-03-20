#include <iostream>
#include <set>
using namespace std;

const int SIZE = 500,
          MAX_RND = 2000;

bool is_prime(int);

int main() {
    // housekeeping
    srand(time(0));
    
    // create an empty set (set: no duplicates, sorted)
    set<int> selection;

    // create & initialize our dataset (an array of 500 randoms)
    int randoms[SIZE];
    for (int i = 0; i < SIZE; i++)
        randoms[i] = rand() % MAX_RND;

    // if anything in randoms[] is 1800-1899, add it to the set
    
    for (int i = 0; i < SIZE; i++)
        if (randoms[i] >= 1800 and randoms[i] < 1900)
            selection.insert(randoms[i]);
    
    cout << "Set of randoms 1800-1899 - set size: " << selection.size() 
         << endl;
    for (int val : selection) 
        cout << val << " "; 
    cout << endl;
    
    selection.clear();  // clears the set
    // if anything in randoms[] is prime, add it to the set
    for (int i = 0; i < SIZE; i++)
        if (is_prime(randoms[i]))
            selection.insert(randoms[i]);
    cout << "Set of primes - set size: " << selection.size() << endl;
    for (int val : selection) cout << val << " "; cout << endl;

    
    selection.clear();  // clears the set
    for (int i = 0; i < SIZE; i++)
        if (randoms[i] % 2 == 0 and randoms[i] % 5 == 0)
            selection.insert(randoms[i]);
    cout << "Set of div2&5 - set size: " << selection.size() << endl;
    for (int val : selection) cout << val << " "; cout << endl;
    
    return 0;
}

bool is_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}