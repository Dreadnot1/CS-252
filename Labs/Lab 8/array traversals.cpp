#include <iostream>
#include <iomanip>
using namespace std;

const int STATES = 7, CAPITOLS = 7, ARRAY_SIZE = 1000, COLUMNS = 10;
const int MIN = 1, MAX = 100;
const int RAND_SIZE = 10;

int main()
{
    srand(time(0));
    
    string states[STATES] = {"West Virginia", "Virginia", "Ohio", "Kentucky",
    "Tennessee", "North Carolina", "South Carolina"};

    string capitols[CAPITOLS] = {"Charleston", "Richmond", "Columbus",
    "Frankfort", "Nashville", "Raleigh", "Columbia"};
    
    int lab[ARRAY_SIZE] = {0};
    
    int random[RAND_SIZE] = {0};
    int highs[RAND_SIZE] = {0};
    
    int num;
    
    //Lab 5-0
    for (int i = 0; i < CAPITOLS; i++) {
        cout << capitols[i] << ", " << states[i] << endl;
    }
    
    cout << endl;
    
    //Lab 5-1
    for (int i = 0; i < ARRAY_SIZE; i++) {
        lab[i] = i;
        
        cout << setw(4) << lab[i];
        if ((i+1) % COLUMNS == 0) {
            cout << endl;
        }
    }
    
    cout << endl;
    
    //Lab 5-2
    cout << "---Random Array---" << endl;
    for (int i = 0, s = 0; i < RAND_SIZE; i++) {
        num = rand() % (MAX-MIN+1) + MIN;
        random[i] = num;
        cout << random[i] << " ";
        
        if (random[i] > 80) {
            highs[s] = random[i];
            s++;
        }
    }
    
    //Range-based for loop to display second array elements > 0
    cout << endl << "---High Array---" << endl;
    for (auto high: highs) {
        if (high > 0) {
            cout << high << " ";
        }
    }

    return 0;
}