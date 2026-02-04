#include <iostream>
using namespace std;

const int MIN = 1;
const int MAX = 4;

int main() {
    int choice, operand1, operand2;

    do {
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

        if (choice != 4) {
            //Getting input for calculations
            cout << "Enter operand 1: ";
            cin >> operand1;
            cout << "Enter operand 2: ";
            cin >> operand2;
        }

        if (choice == 1) {
            cout << operand1 + operand2 << endl;
        } else if (choice == 2) {
            cout << operand1 - operand2 << endl;
        } else if (choice == 3) {
            cout << operand1 * operand2 << endl;
        } else {
            cout << "Goodbye!" << endl;
        }

    } while (choice != 4);

    return 0;
}