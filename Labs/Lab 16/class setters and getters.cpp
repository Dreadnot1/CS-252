#include <iostream>

using namespace std;

//Class definition template
class Goat {
    private:
        //Use setters and getters to access and modify private members
        int age;
        string color;
    public:
        //Function prototypes
        void setAge(int);
        void setColor(string);
        void printGoat();
        int getAge();
        string getColor();
};

void Goat::setAge(int a) { //class methods use scope resolution operator
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
    cout << "Here is your Goat..." << endl;
    cout << "Age: " << age << endl;
    cout << "Color: " << color << endl;
}

int main()
{
    Goat myGoat;
    
    myGoat.setAge(5);
    myGoat.setColor("Brown");
    
    myGoat.printGoat();

    return 0;
}