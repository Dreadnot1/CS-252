#include <iostream>
#include <set>
using namespace std;

int main() {
    srand(time(0));
    set<int> bingo;
    
    bingo.insert(5);
    bingo.insert(61);
    bingo.insert(42);
    bingo.insert(16);
    for (int val : bingo) cout << val << " "; cout << endl;


    // was a certain number already called?
    int val = 43;
    if (bingo.count(val))  // .count() returns 1 (aka 'true') if val is found
        cout << val << " was called.\n";
    else
        cout << val << " was not called.\n";

    cout << "Set size: " << bingo.size() << "  |  ";
    for (int val : bingo) 
        cout << val << " "; 
    cout << endl;

    // whoops, calling 61 was a mistake, erase it, it was 19
    bingo.erase(61);
    bingo.insert(19);

    cout << "Set size: " << bingo.size() << "  |  ";
    for (int val : bingo) cout << val << " "; cout << endl;

    // insert 20 randoms
    bingo.clear();
    for (int i = 0; i < 20; i++)
        bingo.insert(rand() % 75 + 1);
    cout << "Set size: " << bingo.size() << "  |  ";
    for (int val : bingo) cout << val << " "; cout << "\n\n";

    bingo.clear();
    while (bingo.size() < 20)
        bingo.insert(rand() % 75 + 1);
    cout << "Set size: " << bingo.size() << "  |  ";
    for (int val : bingo) cout << val << " "; cout << "\n\n";

    // insert 20 even randoms
    bingo.clear();
    while (bingo.size() < 20) {
        // generate random
        int rnd = rand() % 75 + 1;
        // insert into set if even
        
    }
    

    return 0;
}