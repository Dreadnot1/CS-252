#include <iostream>
#include <map>
#include <string>
using namespace std;

void printPhoneBook(map<string, string>);
void addEntry(map<string, string>&);
void deleteEntry(map<string, string>&);
void searchByName(map<string, string>);
void searchByNumber(map<string, string>);

int main() {
    map<string, string> phoneBook;
    phoneBook["Alice Johnson"] = "304-555-0198";
    phoneBook["Bob Smith"]     = "304-555-0112";
    phoneBook["Charlie King"]  = "304-555-0145";
    phoneBook["Diana Prince"]  = "304-555-0189";
    phoneBook["Evan Wright"]   = "304-555-0177";

    int choice;
    do {
        cout << "\nPHONE BOOK MENU\n";
        cout << "1. Add Entry\n";
        cout << "2. Delete Entry\n";
        cout << "3. Search by Name\n";
        cout << "4. Search by Phone Number\n";
        cout << "5. Print Phone Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch (choice) {
            case 1: addEntry(phoneBook); break;
            case 2: deleteEntry(phoneBook); break;
            case 3: searchByName(phoneBook); break;
            case 4: searchByNumber(phoneBook); break;
            case 5: printPhoneBook(phoneBook); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void printPhoneBook(map<string, string> pb) {
    cout << "\nPhone Book Entries:\n";
    for (auto contact : pb) {
        cout << contact.first << ": " << contact.second << endl;
    }
}

void addEntry(map<string, string>& pb) {
    string name, number;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, number);
    pb[name] = number;
    cout << "Entry added.\n";
}

void deleteEntry(map<string, string>& pb) {
    string name;
    cout << "Enter name to delete: ";
    getline(cin, name);
    if (pb.erase(name))
        cout << "Entry deleted.\n";
    else
        cout << "Name not found.\n";
}

void searchByName(map<string, string> pb) {
    string name;
    cout << "Enter name to search: ";
    getline(cin, name);
    auto it = pb.find(name);
    if (it != pb.end())
        cout << "Found: " << it->first << " - " << it->second << endl;
    else
        cout << "Name not found.\n";
}

void searchByNumber(map<string, string> pb) {
    string number;
    cout << "Enter phone number to search: ";
    getline(cin, number);
    bool found = false;
    for (auto contact : pb) {
        if (contact.second == number) {
            cout << "Number belongs to: " << contact.first << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Phone number not found.\n";
}
