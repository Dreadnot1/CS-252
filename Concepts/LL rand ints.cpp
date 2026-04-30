#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next;
};

int main() {
    srand(time(0));
	int value;
	Node *head;
	int count = 0;

    // adds node at the head
    value = rand() % 10000;
    Node *new_node = new Node;
    if (count == 0) { //if this is the first node, it's the new head
        cout << "Now adding " << value << " as the new head.\n";
        head = new_node;
        new_node->next = nullptr; // pointer to end of linked list
        new_node->value = value; // pointer to the new head
    }
    else {
        cout << "Now adding " << value << " to the head.\n";
        new_node->next = head; 
        new_node->value = value;
        head = new_node;
    }
    count++;
    
    // adds node at the end
    value = rand() % 10000;
	new_node = new Node;   // create a new node
    Node *p = head;  // point to first element in myValues
    if (count == 0) { //if this is the first node, it's the new head
        cout << "Now adding " << value << " as the new head.\n";
        head = new_node;
        new_node->next = nullptr;
        new_node->value = value;
    }
    else {  // traverse to end
        while (p->next)
            p = p->next;
        cout << "Now pointing to last list element: " << p->value << endl;
        cout << "Now adding " << value << " to the end.\n";
        new_node->value = value;
        new_node->next = nullptr;
        p->next = new_node;
    }
    count++;
    
    // adds another node at the end
    value = rand() % 10000;
	new_node = new Node;   // create a new node
    p = head;  // point to first element in myValues
    if (count == 0) { //if this is the first node, it's the new head
        cout << "Now adding " << value << " as the new head.\n";
        head = new_node;
        new_node->next = nullptr;
        new_node->value = value;
    }
    else {  // traverse to end
        while (p->next)
            p = p->next;
        cout << "Now pointing to last list element: " << p->value << endl;
        cout << "Now adding " << value << " to the end.\n";
        new_node->value = value;
        new_node->next = nullptr;
        p->next = new_node;
    }
    count++;
    
    // delete a node
    int delete_term = value;       // value is from previous code block
    Node *current = head;          // *current will traverse the list for us
    Node *previous = nullptr;      // *prev will keep track of one step back
    if (head) {                    // if the list has at least one element
                                   // if the list is empty, do nothing
                                   // determine if the first node has the search term
        if (head->value == delete_term) {
            current = head->next;  // advance t
            delete head;           // deletes the note head is pointing to
            head = current;        // head points to the new head
        }
        else {                     // otherwise we traverse until we find it
            current = head;
            while (current and current->value != delete_term) {
                previous = current;
                current = current->next;
            }
            // at this point, if current isn't at the end of the list,
            // link the previous node to the next node and 
            // delete the current node
            if (current) {
                previous->next = current->next;
                delete current;
                cout << "Deleted term " << delete_term << endl;
            }
        }
    }
    
    // outputs linked list
    // *q will be our pointer that traverses the list
	Node *q = head;
	cout << "Outputting dynamic array of ints:\n\t";
	while (q) {    // this is equivalent to "while (q != nullptr)"
		cout << q->value << " ";
		q = q->next;
	}
	cout << endl;

    return 0;
}