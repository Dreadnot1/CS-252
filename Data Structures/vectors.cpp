#include <iostream>
#include <vector>

using namespace std;

//Some function prototypes
double sum_vec(vector<double>);
vector<int> get_int_vector();

int main() {
    srand(time(0));
    
    /*Vectors are another fundamental data structure with many built-in methods
    Behaves like arrays but with runtime flexibility: grow & shrink dynamically
    Automatic memory management is another added benefit
    Some of the methods: size, push_back, begin, end, erase, and empty*/
    vector<double> readings = {456.56, 789.89, 123.23, 741.74, 852.85, 963.96};
    cout << "Vector sum: " << sum_vec(readings) << endl << endl;
    
    //Traversing a vector that is populated by a function
    vector<int> values = get_int_vector();
    cout << "Obtaining random int vector:\n";
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    cout << endl << endl;

    return 0;
}

//Creates a temporary vector, fills it with random numbers, and returns it
vector<int> get_int_vector() {
    vector<int> temp_v;
    int limit = rand() % 25 + 5;
    for (int i = 0; i < limit; i++) {
        int temp_i = rand() % 10000;
        temp_v.push_back(temp_i);
    }
    return temp_v;
}

//Traverses the vector and returns a sum of all the doubles inside
double sum_vec(vector<double> vec) {
    double sum = 0.0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}