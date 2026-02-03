#include <iostream>
#include <cmath>

using namespace std;

const int COLUMNS = 3;

int main() {
    // Working with exponents
    int x = 3, y = 4;
    int result = pow(x, 2) + (x * y) + pow(y, 2);
    cout << result << endl;

    // Using modulus to make columns
    int sum = 0, number = 12;
    for (int i = 1; i <= number; i++) {
        sum += i;
        cout << sum << "\t";

        if (i % COLUMNS == 0) {
            cout << endl;
        }
    }

    return 0;
}