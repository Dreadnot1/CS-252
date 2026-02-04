#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MXCHAR = 59;
const int MXLEN = 30;
const int MNLEN = 1;

int main() {
    // Using clock to seed srand function
    srand(time(0));

    //Declaring variables to help generate the passcode and store user input
    char rnd;
    string alpha = "@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string build = "";
    int user_input;

    // Getting user input based on code requirements
    cout << "How many characters should the password contain?" << endl;
    cout << "Please choose a length between 1-30: ";
    cin >> user_input;

    // Input validation using constants for the allowed length
    while (user_input < MNLEN || user_input > MXLEN) {
        cout << "Invalid password length! Choose between 1-30: ";
        cin >> user_input;
    }

    /* Iterates through a predefined password string called alpha based on user
    input and constructs a new password by randomly indexing it */
    for (int i = 0; i < user_input; i++) {
        rnd = alpha[rand() % MXCHAR];
        build += rnd;
    }

    cout << "Your generated passkey is: " << build;

    return 0;
}