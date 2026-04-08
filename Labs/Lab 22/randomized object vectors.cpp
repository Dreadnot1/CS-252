// CS 252 | Lab 22 Starter Code | Lair of Villains I
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
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    // printHeader() prints a table header to the console
    // No parameters or return values
    void printHeader() {
        cout << "Name" << setw(HW) << "Evil Rating "
             << "Henchmen " << "Has Cape" << endl;
        cout << "-------------------------------------------------" << endl;
    }
    
};


int main() {
    // declarations
    srand(time(0));
    
    // create a Villain vector of size 20
    vector<Villain> lair(20);
    
    // print the header using the first object
    lair[0].printHeader();
    
    // loop through the vector and add rows to the table
    for (Villain v : lair) {
        v.print();
    }

    return 0;
}