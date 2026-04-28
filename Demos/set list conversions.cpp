#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <list>
using namespace std;

//Function prototypes
set<string> convert_vector(vector<string> input);
list<double> convert_array(double arr[3]);

int main()
{
    //Formatting the console
    cout << fixed << setprecision(4);
    
    //Declarations
    vector<string> elements = {"Todd, Jane, Walter"};
    set<string> outputs = convert_vector(elements);
    double array[3] = {34.32313, 54.3344223, 94.2313};
    list<double> master = convert_array(array);
    
    //Loops through the set
    for (auto output : outputs) {
        cout << output << " ";
    }
    
    cout << endl;
    
    //Loops through the list with an iterator
    for (auto it = master.begin(); it != master.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}

//Converts a string vector into a string set
set<string> convert_vector(vector<string> input) {
    set<string> temp_set;
    string temp_word;
    
    for (int i = 0; i < input.size(); i++) {
        temp_word = input[i];
        temp_set.insert(temp_word);
    }
    return temp_set;
}

//Converts a double array into a double list
list<double> convert_array(double arr[3]) {
    list<double> temp_list;
    double temp_dbl;
    
    for (int i = 0; i < 3; i++) {
        temp_dbl = arr[i];
        temp_list.push_back(temp_dbl);
    }
    return temp_list;
}