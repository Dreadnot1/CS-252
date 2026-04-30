#include <iostream>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

const int MAX_STACK = 20, MIN_RAND = 10, MAX_RAND = 99;

int main() {
    //declarations
    srand(time(0));
    stack<int> iStack;

    //push stack values
    for (int i = 0; i < MAX_STACK; i++) {
        int num = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
        cout << "Pushing " << num << endl;
        iStack.push(num);
    }

    //display stack size
    cout << "The size of the stack is ";
    cout << iStack.size() << endl;
    cout << "Empty? " << iStack.empty() << endl;

    //pop stack values
    for (int i = 0; i < MAX_STACK; i++) {
        cout << "Popping " << iStack.top() << endl;
        iStack.pop();
    }

    return 0;
}