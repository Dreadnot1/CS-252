#include <iostream>
using namespace std;

int main() {
    int value1, value2, value3;
    string name;
    
    cout << "What is 12 + 27?\n\n";
    cout << "Press ENTER to see the answer\n\n";
    cin.get(); //ignores all input and waits for the user to press ENTER
    cout << "The answer is 39." << endl;
    
    //cin stops reading input upon reaching the first space
    cout << "Enter three numbers: ";
    cin >> value1 >> value2 >> value3; //all values can be assigned in one line
    cout << value1 << value2 << value3 << endl;
    
    //Place cin.ignore in-between cin and getline() statements
    cin.ignore(); //flushes the keyboard buffer
    cout << "Enter full name: ";
    
    /*getline() reads all included spaces but stops at a newline character
    it takes a cin object and a variable to store the input in */
    getline(cin, name); 
    
    return 0;
}