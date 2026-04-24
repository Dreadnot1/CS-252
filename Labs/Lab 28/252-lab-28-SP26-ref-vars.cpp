// Lab 28: Reference Variables
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

    void appraise() {
        value = denomination * (2026 - year) * mintRank(mint) / 10.0;
    }

    void deface() {
        denomination = 0.0;
        year = 0;
        mint = 'X';
        value = 0.0;
    }

    void correct(double d, int y, char m) {
        denomination = d;
        year = y;
        mint = m;
        value = d;
    }
};

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

    // auto& (reference): changes persist
    cout << "Bumping value by 1.00 using auto& (reference, persists):\n";
    for (auto& c : coins)
        c.setValue(c.getValue() + 1.00);
    printList(coins);

    // appraise each coin
    cout << "Appraising all coins:\n";
    for (auto& c : coins)
        c.appraise();
    printList(coins);

    // deface the first coin
    cout << "Defacing the first coin:\n";
    cout << "Before: "; coins.front().print();
    coins.front().deface();
    cout << "After:  "; coins.front().print();
    cout << endl;

    // correct the last coin
    double d; int y; char m;
    cout << "Correcting the last coin:\n";
    cout << "Before: "; coins.back().print();
    cout << "Enter denomination: ";    cin >> d;
    cout << "Enter year: ";            cin >> y;
    cout << "Enter mint (P/D/S/W): "; cin >> m;
    coins.back().correct(d, y, m);
    cout << "After:  "; coins.back().print();

    return 0;
}