#include <iostream>
#include <string>
using namespace std;

int main() {
// 1. Declare variables
    int n = 0;
    const int MAX = 50;
    int user_count;
    string compliment = "You've got all the makings of a varsity athlete!";

// 2. Get input (if needed)
    cout << "How many times would you like a compliment? ";

    //Input validation to bound user_count to a constant
    cin >> user_count;
    while (user_count > MAX) {
        cout << "\t Error! Please enter an integer less than or equal to "
        << MAX << " please: ";
        
        cin >> user_count;
    }

// 4. Output results
    for (int i = 0; i < 11; i++) {
        n += i;
        cout << i << "\t" << n << endl;
    }

    for (int i = 0; i < user_count; i++) {
        cout << compliment << endl;
    }

    return 0;
}