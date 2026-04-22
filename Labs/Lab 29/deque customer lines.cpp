#include <iostream>
#include <deque>
using namespace std;

const int SIZE = 5; // fixed size of the starter array

// Function prototypes
int menu();
void print(const deque<string>);
void serve(deque<string> &);
void add(deque<string> &, string);

// Program that simulates a FIFO (First-in, First-out) service line with deques
int main() {
    deque<string> serviceLine;
    string sampleNames[SIZE] = {"Pamm", "Pimm", "Pomm", "Pumm", "Pemm"};
    string customer;
    
    // Populating the deque with example data
    for (int i = 0; i < SIZE; i++) {
        add(serviceLine, sampleNames[i]);
        print(serviceLine);
    }
    
    // Serving two example customers
    serve(serviceLine);
    print(serviceLine);
    serve(serviceLine);
    print(serviceLine);
    
    // Adding two example customers
    add(serviceLine, "Puff");
    print(serviceLine);
    add(serviceLine, "Pudd");
    print(serviceLine);
    
    // Serving the remaining customers
    for (int i = 0; i < SIZE; i++) {
        serve(serviceLine);
        print(serviceLine);
    }
    
    // Adding one last customer before program starts
    add(serviceLine, "Pugg");
    print(serviceLine);
    
    // Main program loop
    int choice = menu();
    while (choice != 4) {
        switch (choice) {
            case 1: { // add a customer to the deque
                string input;
                cout << "Enter a customer name: ";
                cin >> input;
                cout << endl;
                add(serviceLine, input);
                print(serviceLine);
                break;
            }
            case 2: // remove a customer from the deque
                serve(serviceLine);
                print(serviceLine);
                cout << endl;
                break;
            case 3: // print all the customers in the deque
                print(serviceLine);
                break;
            case 4: // exit the program 
                return 0;
        }
        choice = menu();
    }
    
    return 0;
}

// menu() uses console output to show customers in a service line
// parameters: none
// returns:    choice, an int representing the user's input
int menu() {
    int choice = 0;
    
    // Menu display for the user
    cout << "------Customer Service Line------\n";
    cout << "[1] Add a customer\n";
    cout << "[2] Serve a customer\n";
    cout << "[3] Show all waiting customers\n";
    cout << "[4] Exit\n";
    cout << "---------------------------------\n";
    cout << "Enter your choice [1-4]: ";
    cin >> choice;
    
    // Input validation
    while (choice < 1 or choice > 5) {
        cout << "Invalid input. Please enter a number between [1] and [4]: ";
        cin >> choice;
    }
    
    // Flushes the keyboard buffer, then returns the user input
    cin.ignore();
    return choice;
}

// print() loops through a double-ended queue and outputs each string element
// parameters: line, a constant reference to a deque
// returns:    n/a
void print(const deque<string> line) {
    cout << "Customers in queue: ";
    if (line.empty()) {
        cout << "none";
    } else {
        for (string customer : line) {
            cout << customer << " ";
        }
    }
    cout << endl << endl;
}

// serve() takes a deque, outputs the first element, then removes it
// parameters: line, a reference to a deque
// returns:    none
void serve(deque<string> &line) {
    if (line.empty()) {
        cout << "Line is empty!\n" << endl;
    } else {
        string served = line.front();
        line.pop_front();
        cout << served << " was successfully served.\n";
    }
}

// add() takes a deque and pushes a string variable to the back of the queue
// parameters: line, a reference to the deque
//             newc, a string to be added
// returns:    none
void add(deque<string> &line, string newc) {
    line.push_back(newc);
    cout << newc << " was added to the queue.\n";
}