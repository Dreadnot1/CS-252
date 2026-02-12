#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int COLUMNS = 3;

int main() {
    int x = 3, y = 4; //arbitrary values
    int sum = 0; //accumulator
    int user_input;
    
    cout << "Enter number of rows to populate: ";
    cin >> user_input;
    
    // bounding user input for a predictable number of rows
    while (user_input % 3 != 0) {
        cout << "\tERROR: not a multiple of three: ";
        cin >> user_input;
    }
    
    // working with exponents
    int result = pow(x, 2) + (x * y) + pow(y, 2);

    // output formatting using <iomanip> from the standard library
    for (int i = 1; i <= user_input; i++) {
        sum += i;
        // setw(n) automatically uses right-justification
        cout << setw(4) << i
             << setw(6) << sum
             << setw(8) << sum * i << endl;
    }

    return 0;
}