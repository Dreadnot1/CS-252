#include <iostream>

#include <map>

#include <string>


using namespace std;


void addItem(map<string, int>& inv, string item, int qty);

void checkStock(const map<string, int>& inv, string item);

void printInventory(const map<string, int>& inv);


int main() {

	//initializing map with three starting items

	map<string, int> inventory = {{"Wood", 20}, {"Stone", 10}, {"Iron", 5}};


	//demonstrate addItem

	addItem(inventory, "Wood", 5);

	addItem(inventory, "Gold", 1);


	//demonstrate checkStock

	cout << "Wood count: ";

	checkStock(inventory, "Wood");

	cout << "Silver count: ";

	checkStock(inventory, "Silver");


	//demonstrate printInventory

	cout << "\nFull Inventory:" << endl;

	printInventory(inventory);


	return 0;

}


void checkStock(const map<string, int>& inv, string item) {

	auto it = inv.find(item);

	if (it != inv.end()) cout << it->second << endl;

	else cout << "Out of Stock" << endl;

}


void addItem(map<string, int>& inv, string item, int qty) {

	inv[item] += qty;

}


void printInventory(const map<string, int>& inv) {

	for (const auto& [item, qty] : inv) {

		cout << item << ": " << qty << endl;

	}

}