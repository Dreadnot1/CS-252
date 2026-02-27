// CS 252 | Lab 13 | Vectors I
#include <iostream>
#include <iomanip>  // for formatted output
#include <fstream>  // for file output
#include <vector>   // for vectors
using namespace std;

const int COLS7 = 7;

int main() {
    // declarations
    srand(time(0));
    
    // Use #include <vector> for this
    // Vectors are resizeable arrays and much more efficient.

    // Here, I create an empty INT vector named 'numbers'.
    // Note the new syntax for this.
    vector<int> numbers;

    // Here, I create an empty string vector named 'books':
    // Note how the data type goes in the angle brackets <string>
    vector<string> books;

    //*** NOW YOU TRY: create an empty INT vector named 'randoms':
    vector<int> randoms;
    
    // Here, I'm adding an element ("pushing") into the 'numbers' vector.
    // We use the push_back() method that we get with the <vector> library.
    // This method will literally push the number to the back of the vector,
    // so the vector grows.
    numbers.push_back(10);
    // Here, I'm pushing another
    numbers.push_back(52);

    //*** NOW YOU TRY: push any number into the 'randoms' vector
    randoms.push_back(100);

    //*** NOW YOU TRY: push 'rand() % 10' into the randoms vector.
    randoms.push_back(rand() % 10);

    //*** NOW YOU TRY: push any book title into the 'books' vector
    books.push_back("Mistborn");

    // Here, I'm using a loop to push many values into the vector
    // This for loop will push 10 randoms into the vector. Cool!
    for (int i = 0; i < 10; i++)
        numbers.push_back(rand()%10000);

    //*** NOW YOU TRY: push 25 more randoms (make a new range) 
    // into the 'randoms' vector
    for (int i = 0; i < 25; i++) {
        randoms.push_back(rand() % 100);
    }

    // *** NOW YOU TRY TRY: use a for loop and pop off the last 20
    // values from the randoms vector.
    for (int i = 0; i < 20; i++) {
        randoms.pop_back();
    }   


    // HOW TO OUTPUT VECTORS: WE TRAVERSE THEM LIKE ARRAYS
    // There are several ways: index & range-based for loop
    
    // Here, I'm outputting the vector using  an index. This works
    // just like an array as far as indexing. Element 0 is first.
    // Note: vec_name.size() is a built-in function that will 
    // return that vector's current size
    cout << "12-element vector using for loop: \n\t";
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";
    cout << endl << endl;

    //*** NOW YOU TRY: output the 'randoms' vector
    for (int i = 0; i < randoms.size(); i++) {
        cout << randoms[i] << " ";
    }
    cout << endl;

    // Here, I'm outputting the vector using a range-based for loop
    cout << "12-element vector using range-based for loop: \n\t";
    for (int val : numbers)
        cout << val << " ";
    cout << endl << endl;

    //*** NOW YOU TRY: output the 'randoms' vector using the range-based for loop:
    for (auto random: randoms) {
        cout << random << " ";
    }
    cout << endl;

    //*** NOW YOU TRY: output the 'books' vector such that each book is 
    // on its own line:
    for (auto book: books) {
        cout << book << endl;
    }
    cout << endl;

    //*** NOW YOU TRY: use your 'randoms' vector again. Use a regular for-loop for this.
    //    Output your vector in 7 columns.
    //    Here's clever code for this for AFTER you output the number in the for loop,
    //    which will output the endline character every seventh time through the loop:
    //        cout << ((i+1) % COLS7 == 0 ? "\n" : "");
    for (int i = 0; i < randoms.size(); i++) {
        cout << randoms[i] << " ";
        cout << ((i+1) % COLS7 == 0 ? "\n" : "");
    }

    // Here, I'll use a while loop to push values into a vector as long as the user wants
    char again = 'Y';
    double entry;
    vector<double> entries;
    while (toupper(again) == 'Y') {
        cout << "Enter value to push: ";
        cin >> entry;
        entries.push_back(entry);
        cout << "Again? Y/N: ";
        cin >> again;
    }
    // Range-based for loop to output the vector elements
    for (double val : entries)
        cout << val << " ";
    cout << endl;

    // *** NOW YOU TRY: modify the code such that the user specifies
    // that they're done with data entry by entering 0 rather than 'n'
    // use entries.clear() to reset your vector and entry = 1 to reset
    char again2 = 'Y';
    double entry2;
    vector<double> entries2;
    while (toupper(again2) == 'Y') {
        cout << "Enter value to push, or 1 to reset: ";
        cin >> entry2;
        if (entry2 == 1) {
            entries2.clear();
        } else {
            entries2.push_back(entry2);
        }
        cout << "Type Y to continue, or 0 to stop: ";
        cin >> again2;
    }
    
    for (auto entry : entries2) {
        cout << entry << " ";
    }
    cout << endl;

    // *** NOW YOU TRY: modify the code such that if a negative number is
    // entered by chance, it is skimmed and stored in a separate, clandestine
    // vector that you create
    char again3 = 'Y';
    double entry3;
    vector<double> entries3, negatives;
    while (toupper(again3) == 'Y') {
        cout << "Enter value to push, or 1 to reset: ";
        cin >> entry3;
        if (entry3 == 1) {
            entries3.clear();
        } else if (entry3 < 0) {
            negatives.push_back(entry3);
        }
        else {
            entries3.push_back(entry3);
        }
        cout << "Type Y to continue, or 0 to stop: ";
        cin >> again3;
    }
    
    for (auto entry : entries3) {
        cout << entry << " ";
    }
    cout << endl;
        
    return 0;
}