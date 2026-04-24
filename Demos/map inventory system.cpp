#include <iostream>
#include <map>
using namespace std;

// Function prototypes
void addItem(map<string, int> &, string, int, bool);
bool checkStock(const map<string, int> &, string);
void printInventory(const map<string, int> &);

int main()
{
    // Some initial data
    map<string, int> inv = {{"Wood", 10}, {"Stone", 20}, {"Iron", 5}};
    string newItem;
    int newValue;
    bool exists;
    
    // A key-value pair for testing
    newItem = "Copper";
    newValue = 20;
    
    // Testing functions
    exists = checkStock(inv, newItem);
    addItem(inv, newItem, newValue, exists);
    printInventory(inv);
    cout << endl;
    
    // Checking stock again before updating the item
    exists = checkStock(inv, newItem);
    addItem(inv, newItem, newValue, exists);
    printInventory(inv);
    
    return 0;
}

// checkStock() will use .find() and .at() to look for map keys
// parameters: inv, a constant map reference
//             search, the key to search for
// returns:    none
bool checkStock(const map<string, int> &inv, string search) {
    auto it = inv.find(search);
    if (it != inv.end()) {
        // Key exists and it's safe to use .at()
        cout << "Item exists with " << inv.at(search) << " stock." << endl;
        return true;
    } else {
        cout << "Item doesn't exist.\n" << endl;
        return false;
    }
}

// addItem() takes a map reference and creates a key-value pair.
//  If the key already exists, it will increment the value instead.
// parameters: inv, a map reference
//             key, a string variable
//             val, an int variable
//             ex, a bool variable showing if the key-value exists yet
void addItem(map<string, int> &inv, string key, int val, bool ex) {
    if (ex) {
        inv.at(key) += val;
        cout << val << " added to " << key << endl << endl;
    } else {
        inv[key] = val;
        cout << "New item added to inventory.\n" << endl;
    }
}

// printInventory() takes a map and couts the key-value pairs
// parameters: inv, a constant map reference
// returns:    none
void printInventory(const map<string, int> &inv) {
    cout << "--Inventory--" << endl;
    for (const auto& item : inv) {
        cout << item.first << " " << item.second << endl;
    }
}