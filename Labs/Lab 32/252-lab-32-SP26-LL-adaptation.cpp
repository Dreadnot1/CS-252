#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

const int MIN = 5,
          MAX = 15,
          NAMES_MX = 45;

struct Node {
    string value;
    Node *next;
};

int main() {
    // declarations and housekeeping
    srand(time(0));
    string name;
    Node *head;
    int count = 0;
    int size = rand() % (MAX-MIN+1)+MIN;

    // read external data into array
    string names[NAMES_MX];
    int ind = 0;
    ifstream fin("namesXS.txt");
    while (fin >> names[ind++]);
    fin.close();

    // add 5-15 names to the LL
    for (int i = 0; i < size; i++) {
        name = names[rand() % NAMES_MX];
        count++;
        Node *newVal = new Node;

        // adds node at head
        if (count == 1) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = name;
        }
        else {
            newVal->next = head;
            newVal->value = name;
            head = newVal;
        }
    }
    cout << "Added " << size << " names to the LL:\n";
    Node *p = head;
    while (p) {
        cout << "\t" << p->value << endl;
        p = p->next;
    }
    cout << endl;

    // delete a node
    cout << "Who to delete?:\n";
    ind = 1;
    p = head;
    while (p) {
        string lbl = "[" + to_string(ind) + "]  ";
        cout << setw(10) << lbl << p->value << endl;
        p = p->next;
        ind++;
    }
    cout << endl << "> ";
    int choice;
    cin >> choice;
    while (choice < 1 or choice > ind-1) {
        cout << "\tERROR: 1 to "<< ind-1 << " only: ";
        cin >> choice;
    }

    // advance pointer to the selected node to retrieve name
    p = head;
    for (int i = 1; i < choice; i++)
        p = p->next;
    string delete_term = p->value;

    // delete that node
    Node *current = head;
    Node *previous = nullptr;
    if (head) {
        if (head->value == delete_term) {
            current = head->next;
            delete head;
            head = current;
        }
        else {
            current = head;
            while (current and current->value != delete_term) {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete current;
            cout << "Deleted term " << delete_term << endl << endl;
        }
    }
    p = head;
    while (p) {
        cout << "\t" << p->value << endl;
        p = p->next;
    }
    cout << endl;

    // pick a random name, convert to uppercase, insert at tail
    string tail_name = names[rand() % NAMES_MX];
    for (int i = 0; i < tail_name.length(); i++)
        tail_name[i] = toupper(tail_name[i]);

    Node *new_node = new Node;
    new_node->value = tail_name;
    new_node->next = nullptr;

    p = head;
    while (p->next)
        p = p->next;
    p->next = new_node;
    count++;

    cout << "Added \"" << tail_name << "\" to the tail of the LL:\n";
    p = head;
    while (p) {
        cout << "\t" << p->value << endl;
        p = p->next;
    }
    cout << endl;

    return 0;
}