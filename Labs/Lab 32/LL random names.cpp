#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

const int SIZE = 45;           // req. size of the names array
const int NMIN = 0, NMAX = 44; // req. bounds for picking random names
const int LMIN = 5, LMAX = 15; // req. bounds for the size of a linked list

// Creating linked list nodes using structs
struct Node {
	string name;
	Node *next;
};

// Function prototyps
void output(Node *, bool);
void addNodeTail(Node *, string);

int main() {
    // random seed
    srand(time(0));
    
    // reading a file
    ifstream fin("namesXS.txt");
    
    // error checking
    if (!fin) {
        cerr << "Error: could not open file" << endl;
        return 1;
    }
    
    // filling an array with the file contents
    string names[SIZE];
    string temp;
    int counter = 0;
    while (fin >> temp) {
        names[counter] = temp;
        counter++;
    }
    cout << "File data read successfully.\n" << endl;
    
    // pick a random size for the linked list between 5-15
    int linkedSize = rand() % (LMAX - LMIN + 1) + LMIN;
    
    // linked list setup
    Node *head = nullptr;
    int count = 0;
    
    // create a linked list of size [5-15] with random names
    for (int i = 0; i < linkedSize; i++) {
        int index = rand() % (NMAX - NMIN + 1) + NMIN;
        string temp_name = names[index];
        Node *newName = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newName;
            newName->next = nullptr;
            newName->name = temp_name;
        }
        else { // its a second or subsequent node; place at the head
            newName->next = head;
            newName->name = temp_name;
            head = newName;
        }
    }
    
    // shows the linked list
    bool show_index = false;
    cout << "Added " << linkedSize << " names to the linked list:\n";
    output(head, show_index);
    
    // deleting a node
    Node * current = head;
    cout << "DELETE which person? " << endl;
    show_index = true;
    output(head, show_index);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        cout << "Deleting " << current->name << endl << endl;
        delete current;
        current = nullptr;
    }
    show_index = false;
    output(head, show_index);
    
    // pick another random name and capitalize it
    int index = rand() % (NMAX - NMIN + 1) + NMIN;
    string temp_name = names[index];
    for (auto &c : temp_name) {
        c = toupper(c);
    }
    
    // Adds another name to the end of the linked list.
    addNodeTail(head, temp_name);
    output(head, show_index);
    
    return 0;
}

void output(Node * hd, bool show) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    if (show) {
        while (current) {
            cout << "   [" << count++ << "] " << current->name << endl;
            current = current->next;
        }       
    } else {
        while (current) {
            cout << "   " << current->name << endl;
            current = current->next;
        }
    }

    cout << endl;
}

void addNodeTail(Node * hd, string n) {
    Node *newName = new Node;
    Node *p = hd; // points to the header of a linked list

    while (p->next)
        p = p->next;
    cout << "Adding " << n << " to the linked list.\n";
    newName->name = n;
    newName->next = nullptr;
    p->next = newName;
}