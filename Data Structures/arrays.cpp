#include <iostream>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 1000, COLUMNS = 10;
const int MIN = 1, MAX = 100;
const int RAND_SIZE = 10; 
const int SZ = 3; //size declarator (usually a constant)

int main()
{
    srand(time(0));
    
    int lab[ARRAY_SIZE] = {0}; //arrays are containers with a single type
    
    string test2[SZ] = {"Enter", "the", "Sandman"}; //full initilization
    
    int random[RAND_SIZE] = {0}; //partial initialization
    int highs[RAND_SIZE] = {0};
    
    int test1[] = {1,2,3}; //implicit initialization with no size declarator
    
    int num;
    
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
    
    //Range-based for loop to traverse the second array
    cout << endl << "---High Array---" << endl;
    for (auto high: highs) {
        if (high > 0) { //only displays the added elements 
            cout << high << " ";
        }
    }

    return 0;
}