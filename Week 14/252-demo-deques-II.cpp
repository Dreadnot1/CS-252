#include <iostream>
#include <deque>
using namespace std;

int menu();

int main() {
    deque<string> printQueue;
    string jobName;

    int choice = menu();
    while (choice != 5) {
        switch (choice) {
            case 1: // add a print job
                cout << "Enter the name of the print job: ";
                getline(cin, jobName);
                printQueue.push_back(jobName);
                break;
            case 2: // add an urgent print job
                cout << "Enter the name of the urgent print job: ";
                getline(cin, jobName);
                printQueue.push_front(jobName);
                break;
            case 3: // process the next print job
                if (!printQueue.empty()) {
                    cout << "Processing job: " << printQueue.front() << endl;
                    printQueue.pop_front();
                } else {
                    cout << "No jobs to process." << endl;
                }
                break;
            case 4: // show pending print jobs
                if (printQueue.empty()) {
                    cout << "The print queue is empty." << endl;
                }
                else {
                    cout << "Current Print Queue:\n";
                    for (auto job : printQueue)
                        cout << job <<  " | ";
                }
                cout << endl << endl;
                break;
            case 5: // exit
                cout << "Exiting the program." << endl;
                return 0;
        }  // end switch
        choice = menu();
    }  // end while
    return 0;
}

// menu() obtains a validated user menu choice
// parameters: none | returns: user's choice
int menu() {
    int choice = 0;
    cout << "------ Printer Task Queue Menu ------\n";
    cout << "[1] Add a standard print job\n";
    cout << "[2] Add an urgent print job\n";
    cout << "[3] Process the next print job\n";
    cout << "[4] Show all pending print jobs\n";
    cout << "[5] Exit\n";
    cout << "-------------------------------------\n";
    cout << "Enter your choice [1-5]: ";
    cin >> choice;
    while (choice < 1 or choice > 5) {
        cout << "Invalid input. Please enter a number between [1] and [5]: ";
        cin >> choice;
    }
    cin.ignore();
    return choice;
}
