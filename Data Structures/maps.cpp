#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
using namespace std;

const int SIZE = 100,
          MAX_RAND = 25000,
          W1 = 7,
          W2 = 12;

void printMap(map<int, string>);

int main() {
    // declarations and housekeeping
    map<int, string> goats;
    int count;              // for output formatting in columns

    // Add goat information to the map: goat ID number and goat name.
    // In this map, the ID is the key; the name is the value.

    // here we enter the key/value pairs through assignment:
    goats[rand() % 200] = "Billy Bob Gruff";
    goats[rand() % 200] = "Aunt Janie Jane";
    goats[rand() % 200] = "Crazy Charlie";
    goats[55] = "McHoover McFlurry";
    goats[99] = "Goat #99";
    printMap(goats);

    // retrieving specific map elements: we search by key
    int term = 55;
    cout << "Retrieving value at key " << term << ": " << goats.at(term) << endl;
    
    // searching for a specific key
    // the .count() method will return 0 if not found, 1 if found.
    int term0 = 99;
    cout << "Searching for Goat #" << term0 << " using .count(): ";
    if (goats.count(term0) > 0)
        cout << "At " << term0 << ": " << goats.at(term0) << endl;
    else
        cout << "Goat #" << term0 << " not found.\n";
        
    // searching by a value rather than a key
    string term1 = "Aunt Janie Jane";
    bool found = false;
    for (auto [key, val] : goats) {
        if (val == term1) {
            cout << term1 << " found with key value " << key << endl;
            found = true;
            break;
        }
    }
    if (!found) 
        cout << term1 << " was not found in the dictionary.\n";
    cout << endl;

    // erasing a map entry
    cout << "\nErasing Goat #55:\nBefore:\n";
    printMap(goats);
    cout << "After:\n";
    goats.erase(55);
    printMap(goats);
    
    return 0;
}

void printMap(map<int, string> mp) {
    const int W1 = 7;
    cout << "Goat ID -|- Goat Name\n";
    for (auto [key, val]: mp)
        cout << setw(W1) << key << " -|- " 
             << val << endl;
    cout << "Total goats in map: " << mp.size() << endl << endl;
}