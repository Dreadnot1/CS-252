#include <iostream>
using namespace std;

/*Classes are user-defined data types that work as object constructors.
They're analagous to "blueprints" for creating objects.
Attributes (variables) and methods (functions) are referred to as class members.
*/

//Class definition
class Goat {
    /*Public and private are both examples of access specifiers.
    By default, all members of a class are private.*/
    private:
        /*Considered good practice to keep attributes private wherever possible.
        Why? Encapsulation ensures better control of your data.
        Use public setters and getters to access or modify them.*/
        int age; 
        string color;
    public:
        //Method declarations
        void setAge(int); //setter
        void setColor(string);
        void printGoat();
        int getAge(); //getter
        string getColor();

        /*Constructor rules: no return type, usually public, same name as class.
        They're also automatically called when an object is created.*/
        Goat(int a, string c) { //parameterized constructor
            age = a;
            color = c;
        }

        /*Having more than one constructor in the same class allows flexibility.
        This is called Constructor Overloading.*/
        Goat() { //default constructor
            age = 0;
            color = "Unknown";
        }

        //Method defined inside the class
        void talk() {
            cout << "Hello! I'm a talking goat." << endl;
        }
};

//Method definitions outside the class use a scope resolution (::) operator
void Goat::setAge(int a) {
    age = a;
}

void Goat::setColor(string c) {
    color = c;
}

int Goat::getAge() {
    return age;
}

string Goat::getColor() {
    return color;
}

void Goat::printGoat() {
    cout << "You examine the goat carefully." << endl;
    cout << "It looks to be about " << age << " years old." << endl;
    cout << "Its coat is " << color << " in color." << endl;
}

int main()
{
    //Creates Goat objects with different types of constructors
    Goat myGoat(10, "White"); //parameterized
    Goat newGoat; //default
    
    //Method calls
    myGoat.setAge(5);
    myGoat.setColor("Brown");
    myGoat.printGoat();
    newGoat.printGoat();

    return 0;
}