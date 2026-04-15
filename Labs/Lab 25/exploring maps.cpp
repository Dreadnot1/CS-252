#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

const int SIZE = 5;

// Prototypes
void printMap(map<int, string>);
void keySearch(map<int, string>, string);
void valSearch(map<int, string>, int);

int main() {
    // Vectors that contain food names and item numbers to be mapped
    vector<string> itemNames = {
        "Steak and Eggs",
        "Beef Goulash",
        "Make Your Own Pizzas",
        "Veggie Lasagna",
        "BBQ Pork" };
    vector<int> itemNums = {1,2,3,4,5};
    map<int, string> menuItems;

    // Iterates through both vectors simulatenously to create key-value pairs
    // Be aware of what happens if the two vectors aren't the same size...
    // To address this, I used a constant value instead of the vector sizes.
    for (int i = 0; i < SIZE; i++) {
        menuItems[itemNums[i]] = itemNames[i];
    }

    // Prints out the map to start
    printMap(menuItems);
    
    // Erase the third entry and change the second to another food item
    menuItems.erase(3);
    menuItems[2] = "Beef Stew"; // where [2] is the key, not the index
    printMap(menuItems);
    
    // Search for a key by its value
    keySearch(menuItems, "BBQ Pork");
    cout << endl;
    
    // Search for a value by its key
    valSearch(menuItems, 5);
    
    return 0;
}

// printMap() takes a map and outputs its contents to the console
// Parameters: map<int, string>
// Returns:    none
void printMap(map<int, string> pm) {
    cout << "---Cafeteria Menu Items---\n";
    for (auto [key, val]: pm) {
        cout << key << ": " << val << endl;
    }
    cout << endl;
}

// keySearch() takes a map, searches it for a value, and prints out its key
// Parameters: mp, the map to search
//             v, the value to search for
// Returns:    none 
void keySearch(map<int, string> mp, string v) {
    cout << "Searching for food item value: " << v << endl;
    bool found = false;
    for (auto [key, val]: mp) {
        if (val == v) {
            cout << v << " found with an item key of " << key << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << v << " isn't on the menu! Sorry!\n" << endl;
    }
}

// valSearch() takes a map and uses a key to find a particular value
// Paramaters:  mp, the map to search
//              k, the key to search for
// Returns:     none
void valSearch(map<int, string> mp, int k) {
    cout << "Searching for foods with the key of " << k << endl;
    if (mp.count(k) > 0) {
        cout << "Key: " << k << " | " << mp.at(k) << endl;
    } else {
        cout << "Food item #" << k << " not found. Sorry!\n";
    }
}