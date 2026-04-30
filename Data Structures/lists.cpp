// CS 252 | Demo Thu 3/23
// STL::List
#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

void print_list(list<int>, string);
void print_list_rbfl(list<int>);

int main() {
    //Some things about lists: unordered, duplicates OKAY, can be sorted
    list<int> customers;

    //Generally we want to add the value instead of inserting it at a position
    customers.insert(customers.end(), 15);
    customers.insert(customers.end(), 12);
    customers.insert(customers.end(), 19);
    customers.insert(customers.begin(), 332);
    customers.insert(customers.end(), 2);
    customers.insert(customers.end(), 21);
    customers.push_back(222);
    print_list(customers, "Original:" );

    //This is a pointer to the end of the list
    auto it = customers.end();
    for (int i = 0; i < 3; i++)
        it--;
    customers.insert(it, 100);
    
    print_list(customers, "Insert 100 3 from end:");
    // print_list_rbfl(customers);

    it = customers.begin();
    customers.sort();
    print_list(customers, "Sorted:" );

    // insert in order, let's insert 50
    while (*it < 50)
        it++;
    customers.insert(it, 50);
    print_list(customers, "Inserted 50 in order:");

    return 0;
}

void print_list(list<int> lst, string m) {
    cout << setw(30) << m << " ";
    for (auto it = lst.begin(); it != lst.end(); it++ ) {
        cout << *it << " "; //* is the dereferencing operator for pointers
    }
    cout << endl;
}

void print_list_rbfl(list<int> lst) {
    for (int val : lst)
        cout << val << " ";
    cout << endl;
}

/*
Common <list> member functions:
.back()  returns a reference to the last element in the container
.begin() 
.clear()
.emplace(it, args)  emplaces, but requires an iterator pointing to an existing element
.emplace_back(args)  emplaces to the back
.emplace_front(args) emplaces to the front
.empty() returns true if empty; false otherwise
.erase(it)  erases the element pointed to by the iterator
.front() 
.insert(it, value)
.pop_back()
.pop_front()
.push_back()
.push_front()
.remove(value)  removes all elements equal to value
.reverse()
.sort()
.size()
.unique()   deduplicates the list





*/