//# is a preprocessing directive
#include <iostream>
#include <string>

//std contains all the standard library components
using namespace std;

//Functions need a return type
int main() {
    //Strings use double quotes, characters single quotes
    string intro = "Hello World";
    char single = 'H';

    /* Console output uses << operator
    Console input uses >> operator */
    cout << "Hello World\n";

    //Variables also need a return type and can be declared
    int age;
    cin >> age;
    cout << age;

    //0 is standard for everything running properly
    return 100;
} 

/* Some helpful reminders moving forward: 
Lines terminate with a semicolon
Brackets are required for 2+ lines of code
And finally, indentation is not required for the C++ compiler 
(But do it anyway for readability) */
