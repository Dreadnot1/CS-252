#include <iostream>
#include <stack>
#include <ctime>

using namespace std;

const int MAX_RAND = 999;
const int MIN_RAND = 100;
const int NUM_ELEMENTS = 10;

void pushData(stack<int>&);
void popData(stack<int>&);
void displayStatus(const stack<int>&);

int main() {
    //declarations
    srand(time(0));
    stack<int> iStack;

    //push stack values
    for (int i = 0; i < NUM_ELEMENTS; i++) 
        pushData(iStack);

    //display stack status
    displayStatus(iStack);

    //pop stack values
    while (!iStack.empty()) 
        popData(iStack);

    cout << "Stack is empty." << endl;
    return 0;
}

//add random integer to top using defined range
void pushData(stack<int>& s) {
    int val = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
    s.push(val);
    cout << "Pushing: " << val << endl;
}

//remove and print top element
void popData(stack<int>& s) {
    cout << "Popping: " << s.top() << endl;
    s.pop();
}

//display size and top value
void displayStatus(const stack<int>& s) {
    cout << "Stack Size: " << s.size() << endl;
    cout << "Top Element: " << s.top() << endl;
}