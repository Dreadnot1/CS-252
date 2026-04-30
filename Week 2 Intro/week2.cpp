#include <iostream>

using namespace std;

/* Classes are like blueprints for constructing objects
One-to-many relationship, good for reusability
Encapsulation: bundling data and methods into a single unit */
class Student {
    public:
        string degree;
        int credits;
};

/* Structs are similar to classes but members are public by default
instead of private */
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
    int student_count = 15;
    int choice;
    const int MAX_CHOICES = 3;

    bool test_case = true;
    if (test_case) {
        cout << "True\n";
    } else {
        // "\n" is an escape sequence
        cout << "False\n";
    }

    /* Format: start, continue, step
    Has known number of iterations 
    Step values can be used to adjust the increments */
    for (int i = 0; i < 5; i++) {
        cout << i << endl;
    }

    /* Arrays have a fixed-size when declared in C++
    Good for smaller data structures, memory efficient */
    int scores[3] = {70, 80, 90};
    cout << scores[0];

    /* Unknown # of iterations
    Checks for a condition
    Known as a preloop test or pre-test */
    while (student_count <= 18) {
        cout << "Adding student #" << student_count+1 << endl;
        student_count++;
    }

    /* Similar to a regular while loop but executes >= 1 times
    Known as a postloop test or post-test */
    do {
        cout << "[1] Addition\n";
        cout << "[2] Subtraction\n";
        cout << "[3] Quit   Choice --> ";
        cin >> choice;
    } while (choice != 3); 
    /* choice is an integer literal and, in this context, a magic number
    use a constant instead */

    return 0;
}

/* Most code will have the following 4 code blocks
Comments above each, AT MINIMUM:
declarations
input
processing
output */

/* OPERATORS AND EXPRESSIONS
Relational expressions: <, >, ==, <=, >=
Compares two variables using relational operators
Combined assignment operators: +=, -=
++ increment operator, -- decrement operator */
