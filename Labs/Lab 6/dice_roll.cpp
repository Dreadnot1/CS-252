#include <iostream>

using namespace std;

const int MIN = 1, MAX = 6, ROLLS = 150, COLUMNS = 15;

int main() {
    srand(time(0));
    int roll;
    int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;
    
    cout << "---Dice Rolls---" << endl;

    // Logic for the counter variables
    for (int i = 0; i < ROLLS; i++) {
        roll = rand() % (MAX-MIN+1) + MIN;
        if (roll == 1) {
            ones += 1;
        } else if (roll == 2) {
            twos += 1;
        } else if (roll == 3) {
            threes += 1;
        } else if (roll == 4) {
            fours += 1;
        } else if (roll == 5) {
            fives += 1;
        } else {
            sixes += 1;
        }

        // Populating the table with dice rolls
        cout << roll << " ";
        if ((i+1) % COLUMNS == 0) {
            cout << endl;
        }
    }

    // Display for the dice roll stats
    cout << endl << "---Statistics---" << endl;
    cout << "Ones: " << ones << " " << "(" << ones / ROLLS << "%" << ")" << endl;
    cout << "Twos: " << twos << endl;
    cout << "Threes: " << threes << endl;
    cout << "Fours: " << fours << endl;
    cout << "Fives: " << fives << endl;
    cout << "Sixes: " << sixes << endl;

    return 0;
}