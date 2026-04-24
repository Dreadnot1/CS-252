#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

void add(deque<string> &, string);
void serve(deque<string> &);
void print(const deque<string> &);

int main() {
    deque<string> line;
    
    add(line, "Pamm");
    add(line, "Pimm");
    add(line, "Pomm");
    add(line, "Pumm");
    add(line, "Pemm");
    serve(line);
    serve(line);
    add(line, "Puff");
    add(line, "Pudd");
    while (line.size() != 0)
        serve(line);
    add(line, "Pugg");
    
    return 0;
}

void print(const deque<string> &d) {
    for (auto val : d) {
        cout << val << " ";
    }
    cout << endl;
}

void add(deque<string> &d, string n) {
    d.push_back(n);
    cout << "Added: " << n << endl;
    cout << "Queue: ";
    print(d);
    cout << endl;
}

void serve(deque<string> &d) {
    cout << "Served: " << d.front() << endl;
    d.pop_front();
    if (d.size() != 0) {
        cout << "Queue: ";
        print(d);
        cout << endl;
    }
    else
        cout << "Queue: empty\n\n";
    
}