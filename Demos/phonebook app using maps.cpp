#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

const int SIZE = 5, NW = 16, NA = 20; //NW - number width, NA - name width

// Prototypes
map<string, string> addEntry(map<string, string>, string, string);
map<string, string> delEntry(map<string, string>, string);
void printPhonebook(map<string, string>);
void nameSearch(map<string, string>, string);
void numSearch(map<string, string>, string);
void printMenu();
string getName();
string getNumber();

int main() {
    int choice;
    vector<string> names = {
        "Alice Johnson",
        "Bob Smith",
        "Charlie King",
        "Diana Prince",
        "Evan Wright" };
    vector<string> numbers = {
        "304-555-0198",
        "304-555-0112",
        "304-555-0145",
        "304-555-0189",
        "304-555-0177" };
    map<string, string> phonebook;

    // Maps two vectors using a for loop
    for (int i = 0; i < SIZE; i++) {
        phonebook[names[i]] = numbers[i];
    }
    
    // Main loop for the phonebook menu options
    do {
        printMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: { // User wants to add an entry
                string name, number;
                name = getName();
                number = getNumber();
                phonebook = addEntry(phonebook, name, number);
                break;
            }
            case 2: { // User wants to delete an entry
                string name = getName();
                phonebook = delEntry(phonebook, name);
                break;
            }
            case 3: { // User wants to search by number
                string number = getNumber();
                nameSearch(phonebook, number);
                break;
            }
            case 4: { // User wants to search by name
                string name = getName();
                numSearch(phonebook, name);
                break;
            }
            case 5: // User wants to print all entries
                printPhonebook(phonebook);
                break;
        }
    } while (choice != 6);
    
    return 0;
}

// printPhonebook() takes a map and outputs its contents to the console
// Parameters: map<string, string>
// Returns:    none
void printPhonebook(map<string, string> pb) {
    cout << endl << "---PHONEBOOK LISTINGS---\n";
    for (auto [key, val]: pb) {
        cout << setw(NA) << left << key << ": "
             << setw(NW) << right << val << endl;
    }
    cout << endl;
}

// nameSearch() takes a map, searches it for a value, and finds the name key
// Parameters: pb, the Phonebook map to search
//             v, the phone number value
// Returns:    none 
void nameSearch(map<string, string> pb, string v) {
    cout << endl << "Searching for entry: " << v << endl;
    bool found = false;
    for (auto [key, val]: pb) {
        if (val == v) {
            cout << v << " found under " << key << endl << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << v << " isn't listed in your contacts!\n" << endl;
    }
}

// numSearch() takes a map, checks if an input key exists, and prints the value
// Paramaters:  pb, the Phonebook map to search
//              k, the name key
// Returns:     none
void numSearch(map<string, string> pb, string k) {
    cout << endl << "Searching phonebook for: " << k << endl;
    if (pb.count(k) > 0) {
        cout << "Name: " << k << " | " << pb.at(k) << endl << endl;
    } else {
        cout << "No contact information for " << k << " found.\n" << endl;
    }
}

// printMenu() outputs a number of menu options to the console
// No return type or parameters
void printMenu() {
    cout << "---MAIN MENU---" << endl;
    cout << "[1] Add a Number" << endl;
    cout << "[2] Delete a Number" << endl;
    cout << "[3] Search by Number" << endl;
    cout << "[4] Search by Name" << endl;
    cout << "[5] Print All" << endl;
    cout << "[6] Exit" << endl;
    cout << "Choice: ";
}

// addEntry() takes a Phonebook map and adds a new key-value pair from the user
// Parameters: pb, a phonebook map to be updated
//             na, a name from the user
//             pn, a phone number from the user
// Returns:    pb, the updated phonebook map
map<string, string> addEntry(map<string, string> pb, string na, string pn) {
    pb[na] = pn;
    cout << "ADDED!\n" << endl;
    return pb;
}

// delEntry() takes a Phonebook map and deletes a key-value from it
// Parameters: pb, a phonebook map to be updated
//             k, a key from the user
// Returns:    pb, the updated phonebook map
map<string, string> delEntry(map<string, string> pb, string k) {
    pb.erase(k);
    cout << "DELETED!\n" << endl;
    return pb;
}

// getName() prompts the user for a name to add to the Phonebook
// Parameters: none
// Returns:    name, a string input from the user
string getName() {
    string name;
    cout << "Please enter a name: ";
    getline(cin, name);
    return name;
}

// getNumber() prompts the user for a number to add to the Phonebook
// Parameters: none
// Returns:    number, a string input from the user
string getNumber() {
    string number;
    cout << "Please enter a number: ";
    getline(cin, number);
    return number;
}