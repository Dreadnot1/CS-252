#include <iostream>

using namespace std;

const int MIN = 1, MAX = 6;

int main() {
    srand(time(0));
    int roll;
    
    for (int i = 0; i < 150; i++) {
        roll = rand() % (MAX-MIN+1) + MIN;
        cout << roll << " ";
        if ((i+1) % 5 == 0) {
            cout << endl;
        }
    }

    return 0;
}