// Lab 28: Reference Variables | SP26 | Prof Deets
#include <iostream>
#include <iomanip>
#include <list>
#include <string>
using namespace std;

const int W1 = 10,
          W2 = 8;

class Coin {
private:
    double denomination;   // 0.25 for a quarter
    int    year;
    char   mint;           // P, D, S, W
    double value;          // collector value in dollars

public:
    Coin(double d, int y, char m) {
        denomination = d;
        year = y;
        mint = m;
        value = d;
    }

    void setDenomination(double d) { denomination = d; }
    void setYear(int y)            { year = y; }
    void setMint(char m)           { mint = m; }
    void setValue(double v)        { value = v; }

    double getDenomination() const { return denomination; }
    int    getYear()         const { return year; }
    char   getMint()         const { return mint; }
    double getValue()        const { return value; }

    int mintRank(char m) const {
        if (m == 'W') return 4;
        if (m == 'S') return 3;
        if (m == 'D') return 2;
        return 1;  // P
    }

    void print() {
        cout << "$" << fixed << setprecision(2)
             << setw(W1) << left  << denomination
             << setw(W2) << right << year
             << setw(W2) << right << mint
             << "  $" << fixed << setprecision(2) << value << endl;
    }

    bool operator==(const Coin& other) const {
        return (denomination == other.denomination && year == other.year);
    }
    bool operator<(const Coin& other) const {
        return denomination < other.denomination;
    }
    bool operator>(const Coin& other) const {
        return mintRank(mint) > mintRank(other.mint);
    }

    // TODO #2: appraise()
    // update value using: denomination * (2026 - year) * mintRank(mint) / 10.0
    void appraise() {
        setValue(denomination * (2026 - year) * mintRank(mint) / 10.0);
    }

    // TODO #3: deface()
    // zero out the coin: denomination=0.0, year=0, mint='X', value=0.0
    void deface() {
        setDenomination(0.0);
        setYear(0.0);
        setMint('X');
        setValue(0.0);
    }

    // TODO #4: correct(double d, int y, char m)
    // set denomination, year, mint from parameters, reset value to denomination
    void correct(double d, int y, char m) {
        setDenomination(d);
        setYear(y);
        setMint(m);
        setValue(d);
    }

};

// TODO #1: see main() below

void printList(list<Coin> coins) {
    cout << setw(W1+1) << left  << "Denom."
         << setw(W2)   << right << "Year"
         << setw(W2)   << right << "Mint"
         << "  Value" << endl;
    for (auto& c : coins)
        c.print();
    cout << endl;
}

int main() {
    list<Coin> coins;
    coins.push_back(Coin(0.25, 1965, 'P'));
    coins.push_back(Coin(0.10, 1942, 'S'));
    coins.push_back(Coin(0.01, 1909, 'W'));
    coins.push_back(Coin(0.50, 1919, 'D'));

    cout << "Initial list:\n";
    printList(coins);

    // auto (copy): changes do not persist
    cout << "Bumping value by 1.00 using auto (copy, no effect):\n";
    for (auto c : coins)
        c.setValue(c.getValue() + 1.00);
    printList(coins);

    // TODO #1: auto& (reference): changes persist
    // write a range-based for loop using auto& that bumps value by 1.00
    // label the output: "Bumping value by 1.00 using auto& (reference, persists):"
    // call printList() after the loop
    cout << "Bumping value by 1.00 using auto& (reference, persists):\n";
    for (auto& c : coins) {
        c.setValue(c.getValue() + 1.00);
    }
    printList(coins);

    // TODO #2: appraise each coin
    cout << "Appraising all coins:\n";
    // call appraise() on each coin using an auto& loop
    for (auto& c : coins) {
        c.appraise();
    }
    printList(coins);

    // TODO #3: deface the first coin
    cout << "Defacing the first coin:\n";
    cout << "Before: "; coins.front().print();
    // call deface() on coins.front()
    coins.front().deface();
    cout << "After:  "; coins.front().print();
    cout << endl;

    // TODO #4: correct the last coin
    cout << "Correcting the last coin:\n";
    cout << "Before: "; coins.back().print();
    // prompt user for denomination, year, mint then call correct() on coins.back()
    double denom;
    int yr;
    char mi;
    cout << "Type coin's denomination, year, and mint, each separated by a space\n";
    cin >> denom >> yr >> mi;
    coins.back().correct(denom, yr, mi);
    
    cout << "After:  "; coins.back().print();

    return 0;
}