#include <iostream>

using namespace std;

/* Classes are like blueprints for constructing objects
One-to-many relationship, good for reusability
Encapsulation: bundling data and methods into a single unit
*/
class Student {
    public:
        string degree;
        int credits;
};

//Structs are similar to classes but members are public by default instead of private
struct Person {
    string eye_color;
    string hair;
    int age;
    int height;
    int weight;
} myPerson;

int main() {
    Student myStudent;
    myStudent.degree = "Computer Science";

    bool test_case = true;
    if (test_case) {
        cout << "True\n";
    } else {
        // \n is an escape sequence
        cout << "False\n";
    }

    /* Step values can be used to adjust the increments
    Format: start, continue, step 
    Some combined assignment operators: +=, -=
    C++ has ++ increment operator, -- decrement operator
    */
    for (int i = 0; i < 5; i++) {
        cout << i << endl;
    }

    /* Arrays have a fixed-size when declared in C++
    Good for smaller data structures, memory efficient
    */
    int scores[3] = {70, 80, 90};
    cout << scores[0];

    return 0;
}