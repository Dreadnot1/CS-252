#include <iostream>
#include <iomanip>
using namespace std;

const int W15 = 15;

class Student {
private:
    string name;
    double GPA;
    int courseLoad;
public:
    // default constructor
    Student() {
        name = "None";
        GPA = 0.0;
        courseLoad = 0;
    }

    // parameter constructor
    Student(string x, double y, int z) {
        name = x;
        GPA = y;
        courseLoad = z;
    }

    // partial constructor - go in order of declarations
    Student(string n) {
        name = n;
    }

    // getters and setters
    double getGPA()              { return GPA; }
    void setGPA(double g)        { GPA = g; }
    string getName()             { return name; }
    void setName(string n)       { name = n; }
    int getCourseLoad()          { return courseLoad; }
    void setCourseLoad(int c)    { courseLoad = c; }

    // other methods
    void print() {
        cout << setw(W15) << "Name: " << name << endl;
        cout << setw(W15) << "GPA: " << GPA << endl;
        cout << setw(W15) << "Course load: " << courseLoad << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);
    // student 1
    Student craig;
    craig.print();

    // student 2
    Student janice;
    janice.setGPA(3.82);
    janice.setName("Janice");
    janice.setCourseLoad(14);
    janice.print();

    // student 3
    Student molly("Molly", 3.94, 17);
    molly.print();
    
    // student 4
    Student ben("Ben", 2.68, 12);
    ben.print();
    
    // student 5
    Student morgan("Morgan", 4.05, 14);
    morgan.print();

    // student 6
    Student jason("Jason");
    jason.print();
    
    return 0;
}