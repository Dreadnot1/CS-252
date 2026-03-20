// CS 252 | Demo Thu 3/23
// STL::Set
#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <string>
using namespace std;

void print_set(set<int>, string);
void print_set_rbfl(set<int>);

int main() {
    set<int> customers;

    // Sets automatically maintain sorted order and reject duplicates
    customers.insert(15);
    customers.insert(12);
    customers.insert(19);
    customers.insert(332);
    customers.insert(2);
    customers.insert(21);
    customers.insert(222);
    print_set(customers, "Original:");
    print_set_rbfl(customers);

    // Demonstrate duplicate rejection
    customers.insert(19);   // already exists — silently ignored
    customers.insert(12);   // already exists — silently ignored
    print_set(customers, "After dup inserts:");

    // Find an element using an iterator
    auto it = customers.find(19);
    if (it != customers.end())
        cout << setw(30) << "Found via .find():" << " " << *it << endl;

    // Erase by value
    customers.erase(332);
    print_set(customers, "Erased 332:");

    // Erase by iterator
    it = customers.find(2);
    if (it != customers.end())
        customers.erase(it);
    print_set(customers, "Erased 2 via iterator:");

    // Count (returns 0 or 1 for sets — useful for membership check)
    cout << setw(30) << "Count of 19:" << " " << customers.count(19) << endl;
    cout << setw(30) << "Count of 999:" << " " << customers.count(999) << endl;

    // lower_bound / upper_bound — like "find neighbors" in sorted order
    customers.insert(50);
    customers.insert(75);
    customers.insert(100);
    print_set(customers, "After more inserts:");

    auto lb = customers.lower_bound(50);  // first element >= 50
    auto ub = customers.upper_bound(50);  // first element >  50
    cout << setw(30) << "lower_bound(50):" << " " << *lb << endl;
    cout << setw(30) << "upper_bound(50):" << " " << *ub << endl;

    // Erase a range using lower/upper bound
    auto start = customers.lower_bound(50);
    auto end   = customers.upper_bound(75);
    customers.erase(start, end);          // erases 50 and 75, stops before 100
    print_set(customers, "Erased [50,75]:");

    // Size and empty check
    cout << setw(30) << "Size:" << " " << customers.size() << endl;
    cout << setw(30) << "Empty?:" << " " << (customers.empty() ? "yes" : "no") << endl;

    // Clear
    customers.clear();
    cout << setw(30) << "After .clear(), empty?:" << " " << (customers.empty() ? "yes" : "no") << endl;

    // -------------------------------------------------------
    // File I/O demo: read names from file into a set<string>
    // -------------------------------------------------------
    cout << "\n--- Reading names from file ---" << endl;

    ifstream fin("252-demo-set.txt");
    ofstream fout("252-demo-set-d.txt");

    if (!fin) {
        cerr << "Error: could not open 252-demo-set.txt" << endl;
        return 1;
    }

    set<string> names_set;
    string temp;

    while (fin >> temp)
        names_set.insert(temp);

    cout << setw(30) << "Names (sorted, deduped):" << endl;
    for (string nm : names_set) {
        cout << setw(32) << nm << endl;
        fout << nm << endl;
    }

    cout << setw(30) << "Unique name count:" << " " << names_set.size() << endl;

    // Demonstrate find on the string set
    cout << "\n--- Search demo on names ---" << endl;
    string search = "Alice";
    auto sit = names_set.find(search);
    if (sit != names_set.end())
        cout << setw(30) << "Found:" << " " << *sit << endl;
    else
        cout << setw(30) << "Not found:" << " " << search << endl;

    fin.close();
    fout.close();

    return 0;
}

void print_set(set<int> s, string m) {
    cout << setw(30) << m << " ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void print_set_rbfl(set<int> s) {
    for (int val : s)
        cout << val << " ";
    cout << endl;
}

/*
Common <set> member functions:
.begin()                    returns iterator to first element
.clear()                    removes all elements
.count(value)               returns 1 if value exists, 0 if not (sets have no duplicates)
.emplace(args)              constructs and inserts in-place
.empty()                    returns true if empty; false otherwise
.end()                      returns iterator past the last element
.equal_range(value)         returns pair of iterators {lower_bound, upper_bound}
.erase(value)               removes element by value
.erase(it)                  removes element pointed to by iterator
.erase(it_start, it_end)    removes elements in range [it_start, it_end)
.find(value)                returns iterator to element, or .end() if not found
.insert(value)              inserts value; no-op if value already exists
.lower_bound(value)         iterator to first element >= value
.size()                     returns number of elements
.upper_bound(value)         iterator to first element >  value
*/