#include <iostream>
using namespace std;

int main() {
    const int MIN = 1;
    const int MAX = 4;
    int choice, operand1, operand2;

    //Menu options
    cout << "Enter [1] for addition\n";
    cout << "Enter [2] for subtraction\n";
    cout << "Enter [3] for multiplication\n";
    cout << "Enter [4] to quit\n";

    //Input validation
    cin >> choice;
    while (choice < MIN || choice > MAX) {
        cout << "Invalid choice, please try again: ";
        cin >> choice;
    }

    if (choice == 4) {
        cout << "Goodbye!";
        exit(0);
    }

    //Getting input for calculations
    cout << "Enter operand 1: ";
    cin >> operand1;
    cout << "Enter operand 2: ";
    cin >> operand2;

    if (choice == 1) {
        cout << operand1 + operand2;
    } else if (choice == 2) {
        cout << operand1 - operand2;
    } else {
        cout << operand1 * operand2;
    }

    return 0;
}