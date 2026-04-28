#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Student { // members public by default
    int ID;
    string Name;
};


// Prototypes
void vectorSearch(const vector<Student>&, int);
void mapSearch(const map<int, string>&, int);


// Compare and contrast the difference between sequence and associative containers
int main() {
    vector<Student> students = {{101, "Alice"}, {102, "Bob"}, {103, "Charles"}};
    map<int, string> moreStudents = {{101, "Alice"}, {102, "Bob"}, {103, "Charles"}};

    // Search a sequential vector for two IDs
    vectorSearch(students, 103);
    vectorSearch(students, 104);
    
    // Create an associative map and search it two IDs
    mapSearch(moreStudents, 104);
    mapSearch(moreStudents, 103);
    
    return 0;
}

// Desc: searches a Student vector for an id number and couts the student name
// Params: vec, reference to the Student vector
//         id, the struct member to search for
// Return: none
void vectorSearch(const vector<Student> &vec, int id) {
    bool found;
    for (const auto &v : vec) {
        if (v.ID == id) {
            cout << "Found student " << v.Name 
                 << " with ID " << v.ID
                 << endl << endl;
            found = true;
            break;
        } else if (!found) {
            cout << "Student not found with that ID number.\n" << endl;
        }
    }
}

// Desc: searches a Student map for an id number and couts the student name
// Params: sm, reference to the Student map
//         id, the key to search for in the map
// Return: none
void mapSearch(const map<int, string> &smap, int id) {
    auto it = smap.find(id);
    if (it != smap.end()) {
        cout << "Found student " << it->second
             << " with ID " << it->first
             << endl << endl;
    } else {
        cout << "Student doesn't exist.\n" << endl;
    }
}

// Questions
// 1. vectorSearch needs to manually iterate through every element to find the ID
// whereas mapSearch uses the find() method to return an iterator that points to
// the position of the ID in the map. Vectors are sequences, maps are associative.

// 2.vectorSearch takes linear time. In the worst case, you might have to check
// all 5 million students. mapSearch uses a binary tree implementation which 
// only requires logarithmic time, even with 5 million students.

// 3. A vector would be a better choice for a dataset where position matters
// because it would allow us to index. If we wanted to make a habit tracking
// app where we only care about how many times a user does something each day,
// it would be very efficient to simply index the day and get the value.