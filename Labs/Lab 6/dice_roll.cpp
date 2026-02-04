#include <iostream>
#include <cmath>

using namespace std;

const int MIN = 1, MAX = 6, ROLLS = 150, COLUMNS = 15;

int main() {
    srand(time(0));
    int roll;
    float ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;
    
    cout << "---------Dice Rolls---------" << endl;

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

    // Calculating percentages for later display
    float dis_one = ones / ROLLS * 100;
    float dis_two = twos / ROLLS * 100;
    float dis_three = threes / ROLLS * 100;
    float dis_four = fours / ROLLS * 100;
    float dis_five = fives / ROLLS * 100;
    float dis_six = sixes / ROLLS * 100;

    // Display for the dice roll statistics
    cout << endl << "----Statistics----" << endl;
    cout << "Ones: " << ones << " " << "(" << dis_one << "%" << ")" << endl;
    cout << "Twos: " << twos << " " << "(" << dis_two << "%" << ")" << endl;
    cout << "Threes: " << threes << " " << "(" << dis_three << "%" << ")" << endl;
    cout << "Fours: " << fours << " " << "(" << dis_four << "%" << ")" << endl;
    cout << "Fives: " << fives << " " << "(" << dis_five << "%" << ")" << endl;
    cout << "Sixes: " << sixes << " " << "(" << dis_six << "%" << ")" << endl;
    cout << endl;

    return 0;
}