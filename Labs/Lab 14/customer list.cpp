// CS 252 | Demo Thu 3/23
// STL::List
#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
using namespace std;

//Function prototypes
void print_list(list<string>);
list<string> read_data();
bool coin_toss();

int main() {
    srand(time(0));
    
    list<string> customers = read_data();
    list<string> waiting_line;
    
    //Adding 5 initial customers to the waiting line
    auto it = customers.begin();
    for (int i = 0; i < 5; i++) {
        waiting_line.push_back(*it);
        it++;
    }
    
    for (int i = 0; i < 5; i++) {
        bool can_cut = coin_toss();
        bool served = coin_toss();
        
        //New customers can cut the line or join at the back
        if (can_cut == true) {
            waiting_line.push_front(*it);
            cout << *it << " can cut the line." << endl;
            it++;
        } else if (can_cut == false) {
            waiting_line.push_back(*it);
            cout << *it << " must go to the back of the line." << endl;
            it++;
        }
        
        /*Served customers leave the front of the line
        Impatient karens will leave the back of the line*/
        if (served == true) {
            cout << "A satisfied customer is served and leaves." << endl;
            waiting_line.pop_front();
        } else if (served == false) {
            cout << "A Karen is tired of waiting and leaves." << endl;
            waiting_line.pop_back();
        }
        
        //Display formatting
        cout << endl;
        print_list(waiting_line);
        cout << endl;
    }

    return 0;
}

//Flips a coin to determine if a customer gets to join or skip the line
bool coin_toss() {
    int heads = 0, tails = 1, result;
    result = rand() % (tails-heads+1) + heads;
    if (result == 0) {
        return false;
    } else {
        return true;
    }
}

//Prints out the contents of a list with a RBFL
void print_list(list<string> clist) {
    for (string c : clist) {
        cout << c << endl;
    }
}

//Reads file data and returns it as a list
list<string> read_data() {
    ifstream fin("252-demo-list-names.txt");
    list<string> customer_data;
    string data;
    
    while (fin >> data) {
        customer_data.push_back(data);
    }
    fin.close();
    return customer_data;
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