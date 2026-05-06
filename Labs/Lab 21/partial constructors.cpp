// CS 252 | Lab 21 Starter Code | Partial Constructors 
#include <iostream>
#include <vector>
using namespace std;

class Villain {
private:
    string name;
    int    evilRating;    // 1-10
    int    henchmenCount;
    bool   hasCape;

public:
    // parameter constructor
    Villain(string n, int er, int hc, bool cape) 
        { name = n; evilRating = er; henchmenCount = hc; hasCape = cape; }

    // default constructor
    // TODO: write a default constructor that sets: name="Unknown", evilRating=1, 
    //                                              henchmenCount=0, hasCape=false
    Villain() {
        name = "Unknown";
        evilRating = 1;
        henchmenCount = 0;
        hasCape = false;
    }

    // partial constructor (go in order of private member declarations)
    // TODO: write a constructor that takes only name and evilRating as parameters
    // and sets the other two attributes to those default values
    Villain(string n, int e) {
        name = n;
        evilRating = e;
        henchmenCount = 0;
        hasCape = false;
    }

    // setters and getters
    void   setName(string n)        { name = n; }
    void   setHasCape(bool cape)    { hasCape = cape; }
    string getName()                { return name; }
    bool   getHasCape()             { return hasCape; }
    // TODO: write setters and getters for evilRating and henchmenCount
    
    //EvilRating methods
    void setEvilRating(int e) {
        evilRating = e;
    }
    int getEvilRating() {
        return evilRating;
    }
    
    //HenchmenCount methods
    void setHenchmenCount(int h) {
        henchmenCount = h;
    }
    int getHenchmenCount() {
        return henchmenCount;
    }

    // other methods
    void print() {
        cout << "Name:       " << name         << endl;
        cout << "Evil Rating:" << evilRating   << endl;
        cout << "Henchmen:   " << henchmenCount << endl;
        cout << "Has Cape:   " << hasCape       << endl;
    }

    // TODO: write a method called describe() that prints a sentence like:
    // Dr. Doom has an evil rating of 9 and commands 47 henchmen.
    void describe() {
        cout << name << " has an evil rating of " << evilRating
             << " and commands " << henchmenCount << " henchmen."
             << endl;
    }
};


int main() {
    // part 1: parameter constructor
    Villain v1("Dr. Doom", 9, 47, true);
    v1.print();

    cout << endl;

    // part 2: uncomment after writing the default constructor
    Villain v2;
    v2.print();

    cout << endl;

     // part 3: uncomment after writing the partial constructor
    Villain v3("Joker", 8);
    v3.print();

    cout << endl;

    // part 4: uncomment after writing describe()
    v1.describe();
    v2.describe();
    v3.describe();

    cout << endl;

    // part 5: use setters to update v1's henchmen count to 100, then print again
    v1.setHenchmenCount(100);
    v1.describe();
    
    // part 6: create a vector and populate it with objects
    vector<Villain> lair(20);
    for (Villain v : lair) {
        v.describe();
    }

    return 0;
}