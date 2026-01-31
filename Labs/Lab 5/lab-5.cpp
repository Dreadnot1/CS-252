#include <iostream>
using namespace std;

int main() {
    const int MIN = 1;
    int count;

    cout << "Enter an integer greater than 1: ";
    cin >> count;
    while (count <= MIN) {
        cout << "Not a valid number, please try again: ";
        cin >> count;
    }

    for (int i = 1; i <= count; i++) {
        cout << i << endl;
    }

    return 0;
}