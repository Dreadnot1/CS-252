#include <iostream>
#include <stack>
#include <ctime>

using namespace std;

const int MAX_SIZE = 10, MIN_NUM = 100, MAX_NUM = 999;

void pushData(stack<int> &);
void popData(stack<int> &);
void displayStatus(stack<int> &);

int main()
{
    srand(time(0));
    stack<int> rStack;
    
    // Adds 10 random integers to rStack with pushData()
    pushData(rStack);
    
    // Shows the size of the stack and its top value
    displayStatus(rStack);
    
    // Removes all the data from the stack
    popData(rStack);

    return 0;
}

// Desc: pushes random integers into a stack using .push() inside a for loop
// Params: rst, a stack to be filled
// Returns: nothing
void pushData(stack<int> &rst) {
    for (int i = 0; i < MAX_SIZE; i++) {
        int num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        cout << "Adding " << num << " to the stack.\n" << endl;
        rst.push(num);
    }
}

// Desc: removes data from the top of a stack using .pop() inside a for loop
// Params: rsp, a stack from which elements are popped
// Returns: nothing
void popData(stack<int> &rsp) {
    if (!rsp.empty()) {
        for (int i = 0; i < MAX_SIZE; i++) {
            cout << "Removing " << rsp.top() << " from the stack.\n" << endl;
            rsp.pop();
        }  
    } else {
        cout << "Stack is empty.\n" << endl;
    }
}

// Desc: reports the size and top value of the stack with .size() and .top()
// Params: rsd, a random stack to display
// Returns: nothing
void displayStatus(stack<int> &rsd) {
    cout << "---STACK REPORT---" << endl;
    cout << "Size of the stack: " << rsd.size() << endl;
    cout << "Top element: " << rsd.top() << endl;
    cout << "------------------\n" << endl;
}