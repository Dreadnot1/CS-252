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
    // Student 1
    Student student1;
    student1.ID = 1;
    student1.Name = "Amy";
    
    // Student 2
    Student student2;
    student2.ID = 2;
    student2.Name = "Brad";
    
    // Student 3
    Student student3;
    student3.ID = 3;
    student3.Name = "Charles";
    
    // Student 4
    Student student4;
    student4.ID = 4;
    student4.Name = "Derrick";
    
    // Student 5
    Student student5;
    student5.ID = 5;
    student5.Name = "Erica";

    // Create a sequential vector of Students and search it for two IDs
    vector<Student> students = {student1, student2, student3, student4, student5};
    vectorSearch(students, 3);
    vectorSearch(students, 6);
    
    // Create an associative map of Students and search it for Charles
    map<int, string> moreStudents;
    moreStudents[student1.ID] = student1.Name;
    moreStudents[student2.ID] = student2.Name;
    moreStudents[student3.ID] = student3.Name;
    moreStudents[student4.ID] = student4.Name;
    moreStudents[student5.ID] = student5.Name;
    mapSearch(moreStudents, 3);
    mapSearch(moreStudents, 6);
    
    return 0;
}

// Desc: searches a Student vector for an id number and couts the student name
// Params: vec, reference to the Student vector
//         id, the struct member to search for
// Return: none
void vectorSearch(const vector<Student> &vec, int id) {
    for (const auto &v : vec) {
        if (v.ID == id) {
            cout << "Found student " << v.Name 
                 << " with ID " << v.ID
                 << endl << endl;
        } else {
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