// CS 252 | Lab 24 | Lair of Villains III
// Spring 2026 | Prof Deets
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int HW = 26; // header width for name
const int NW = 16; // width for name
const int RW = 13; // width for evilRating
const int HCW = 9; // width for henchmenCount
const int CW = 9; // width for hasCape

// prototypes
void printMenu();


class Villain {
private:
    string name;
    int    evilRating;    // 1-10
    int    henchmenCount;
    bool   hasCape;

public:
    // default constructor - randomizes all attributes
    Villain() {
        string names[] = {
            "Dr. Doom", "Joker", "Magneto", "Thanos", "Lex Luthor",
            "Loki", "Ultron", "Venom", "Carnage", "Green Goblin",
            "Red Skull", "Mysterio", "Vulture", "Electro", "Sandman",
            "Rhino", "Shocker", "Kingpin", "Morbius", "Scorpion",
            "Doctor Octopus", "Sinister Six", "Hydro-Man", "Tombstone", "Hammerhead",
            "Whiplash", "Justin Hammer", "Abomination", "Leader", "Baron Zemo",
            "Crossbones", "Taskmaster", "Ghost", "Yellowjacket", "Malekith",
            "Kurse", "Ronan", "Nebula", "Ego", "Hela",
            "Surtur", "Dormammu", "Kaecilius", "Mordo", "Vulcan",
            "Mister Sinister", "Apocalypse", "Mystique", "Sabretooth", "Juggernaut",
            "Blob", "Pyro", "Toad", "Callisto", "Deathstrike",
            "Omega Red", "Deadpool", "Cable", "Stryfe", "Madelyne Pryor",
            "Doomsday", "Brainiac", "Darkseid", "General Zod", "Bizarro",
            "Metallo", "Parasite", "Toyman", "Livewire", "Atomic Skull",
            "Black Manta", "Ocean Master", "Cheetah", "Circe", "Ares",
            "Sinestro", "Parallax", "Atrocitus", "Larfleeze", "Anti-Monitor",
            "Bane", "Scarecrow", "Riddler", "Penguin", "Two-Face",
            "Poison Ivy", "Harley Quinn", "Mr. Freeze", "Ra's al Ghul", "Clayface",
            "Killer Croc", "Firefly", "Mad Hatter", "Victor Zsasz", "Deathstroke",
            "Slade Wilson", "Black Adam", "Reverse Flash", "Captain Cold", "Gorilla Grodd"
        };
        name         = names[rand() % 100];
        evilRating   = rand() % 10 + 1;
        henchmenCount = rand() % 200;
        hasCape      = rand() % 2;
    }

    // print() prints all the attributes of a Villain object
    // No parameters or return values
    void print() {
        cout << left << setw(NW) << name << right
             << setw(RW) << evilRating
             << setw(HCW) << henchmenCount
             << setw(CW);
        if (hasCape == 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    
    // printHeader() prints a table header to the console
    // Parameters: an int value that determines the type of header
    //          0: All Villains
    //          1: Caped Villains
    //          2: Capeless Villains
    // Returns: none
    void printHeader(int h) {
        if (h == 1) {
            cout << endl << "*** Caped Villains ***" << endl;
            cout << "Name" << setw(HW) << "Evil Rating "
                 << "Henchmen " << "Has Cape" << endl;
            cout << "-------------------------------------------------" << endl;
        } else if (h == 2) {
            cout << endl << "*** Capeless Villains ***" << endl;
            cout << "Name" << setw(HW) << "Evil Rating "
                 << "Henchmen " << "Has Cape" << endl;
            cout << "-------------------------------------------------" << endl;           
        } else {
            cout << endl << "*** Lair Villains ***" << endl;
            cout << "Name" << setw(HW) << "Evil Rating "
                 << "Henchmen " << "Has Cape" << endl;
            cout << "-------------------------------------------------" << endl;
        }
    }
    
    // hasCapeOn() is a getter for the hasCape attribute
    bool hasCapeOn() {
        return hasCape;
    }
    
    // recruitHenchmen() is a setter for the henchmenCount attribute
    void recruitHenchmen(int add) {
        henchmenCount += add;
    }
    
};


int main() {
    // declarations
    srand(time(0));
    
    // create a Villain vector of size 20
    vector<Villain> lair(20);
    
    // menu system with do while and switch statements
    // loops until user quits with option [9]
    int choice;
    do {
        switch (choice) {
            case 1: { // adds a new Villain object to the lair
                Villain vill;
                lair.push_back(vill);
                cout << "Added new Villain. Lair size: " << lair.size();
                cout << endl << endl;
                break;
            }
            case 2: { // creates a user defined number of Villain objects
                int num;
                cout << "How many Villains would you like to add? ";
                cin >> num;
                for (int i = 0; i < num; i++) {
                    Villain vill;
                    lair.push_back(vill);
                }
                cout << "Added " << num << " new Villains. Lair size: "
                     << lair.size() << endl << endl;
                break;
            }
            case 3: // removes a Villain from the end of the vector
                lair.pop_back();
                cout << "Removed a Villain. Lair size: " << lair.size()
                     << endl << endl;
                break;
            case 4: { // prints all of the Villains attributes to console
                if (lair.size() == 0) {
                    cout << endl << "*** Lair Villains ***" << endl;
                    cout << "The Lair is empty." << endl << endl;
                } else {
                    lair[0].printHeader(0);
                    for (Villain v : lair) {
                        v.print();
                    }
                    cout << endl;
                }
                break;
            }
            case 5: { // outputs all the Villains with capes
                int capeHeader = 1, capeCount = 0;
                lair[0].printHeader(1);
                bool capeOn;
                for (Villain v : lair) {
                    capeOn = v.hasCapeOn();
                    if (capeOn == 1) {
                        v.print();
                        capeCount += 1;
                    } else {
                        continue;
                    }
                }
                cout << endl << capeCount << " Villains with capes." 
                     << endl << endl;
                break;
            }
            case 6: { // outputs all the Villains without capes
                int noCapeHeader = 2, noCapeCount = 0;
                lair[0].printHeader(noCapeHeader);
                bool capeOff;
                for (Villain v : lair) {
                    capeOff = v.hasCapeOn();
                    if (capeOff == 0) {
                        v.print();
                        noCapeCount += 1;
                    } else {
                        continue;
                    }
                }
                cout << endl << noCapeCount<< " Villains without capes." 
                     << endl << endl;
                break;
            }
            case 7: { // recruits 3 henchmen for each Villain
                int recruits = 3;
                for (int i = 0; i < lair.size(); i++) {
                    lair[i].recruitHenchmen(recruits);
                }
                // The below code didn't work because v was only a copy
                // I needed to index the objects instead to change their attributes
                /*for (Villain v : lair) {
                    v.recruitHenchmen(recruits);
                }*/
                cout << endl << "3 Henchmen recruited for each Villain." 
                     << endl << endl;
                break;
            }
            case 8: // clears the Villain lair vector
                lair.clear();
                cout << endl << "The Lair has been closed with all Villains rehomed."
                     << endl << endl;
                break;
        }
        printMenu();
        cin >> choice;
    } while (choice != 9); //option 9 exits the loop and closes the program

    return 0;
}

// printMenu() outputs a number of menu options to the console
// No return type or parameters
void printMenu() {
    cout << "--- Lair Menu ---" << endl;
    cout << "[1] Add Villain to Lair" << endl;
    cout << "[2] Add n Villains to Lair" << endl;
    cout << "[3] Remove Villain from Lair" << endl;
    cout << "[4] Output All Lair Occupants" << endl;
    cout << "[5] Output Occupants With Capes" << endl;
    cout << "[6] Output Occupants Without Capes" << endl;
    cout << "[7] Recruit Henchmen" << endl;
    cout << "[8] Close Lair" << endl;
    cout << "[9] Quit Program" << endl;
    cout << "Choice: ";
}