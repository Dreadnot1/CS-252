#include <iostream>
#include <deque>
using namespace std;

int main() {
    // Initializing a deque
    deque<int> storage;

    // Pushing elements into the deque
    cout << "Pushing elements into the deque:\n";
    for (int i = 1; i <= 5; i++) {
        storage.push_back(i * 10);  // Add to the back
        storage.push_front(i * -10); // Add to the front
    }

    // Displaying elements of the deque
    cout << "Current deque elements:\n";
    for (int val : storage) 
        cout << val << " ";
    cout << endl << endl;

    // Popping elements from the deque
    cout << "Popping elements from the front and back of the deque:\n";
    storage.pop_front(); // Remove from the front
    storage.pop_back();  // Remove from the back

    // Displaying elements of the deque after popping
    cout << "Deque after popping from both ends:\n";
    for (int val : storage) 
        cout << val << " ";
    cout << endl << endl;

    // Accessing the front and back element
    cout << "Front element: " << storage.front() << endl;
    cout << "Back element: " << storage.back() << endl << endl;

    // Inserting element at the third position
    cout << "Inserting element at the third position:\n";
    storage.insert(storage.begin() + 2, 555);
    for (int val : storage) 
        cout << val << " ";
    cout << endl << endl;

    // Erasing the third element
    cout << "Erasing the third element:\n";
    storage.erase(storage.begin() + 2);
    for (int val : storage) 
        cout << val << " ";
    cout << endl << endl;

    // Clearing the deque
    cout << "Clearing the deque.\n";
    storage.clear();
    // this statement uses a conditional operator in a cout object
    // if storage is empty, it outputs "Yes", else "No"
    cout << "Empty: " << (storage.empty() ? "Yes" : "No") << endl;

    return 0;
}
