#include <iostream>
#include <string>
using namespace std;

int main() {
// 1. Declare variables
    int n = 0;
    int user_count;
    string compliment = "You're the best around, just like the Karate Kid!";
// 2. Get input (if needed)
    cout << "How many times would you like a compliment? ";
    cin >> user_count;
// 3. Process data
    for (int i = 0; i < 11; i++) {
        n += i;
        cout << i << "\t" << n << endl;
    }

    for (int i = 0; i < user_count; i++) {
        cout << compliment << endl;
    }
    
// 4. Output results
    return 0;
}