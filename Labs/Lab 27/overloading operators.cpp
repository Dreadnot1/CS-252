// Lab 27: Operator Overloading | SP26 | Prof Deets
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int W1 = 10,
          W2 = 8;

class Coin {
private:
    double denomination;   // 0.25 for a quarter
    int    year;
    char   mint;           // P, D, S, W

public:
    Coin() {
        denomination = 0.0;
        year = 1000;
        mint = 'X';
    }
    Coin(double d, int y, char m) {
        denomination = d;
        year = y;
        mint = m;
    }
    Coin(double d) {
        denomination = d;
        year = 1000;
        mint = 'X';
    }

    void setDenomination(double d) { denomination = d; }
    void setYear(int y)            { year = y; }
    void setMint(char m)           { mint = m; }

    double getDenomination() const { return denomination; }
    int    getYear()         const { return year; }
    char   getMint()         const { return mint; }

    void print() {
        cout << "$" << fixed << setprecision(2)
             << setw(W1) << left  << denomination
             << setw(W2) << right << year
             << "  " << mint << endl;
    }

    int mintRank(char m) const {
        if (m == 'W') return 4;
        if (m == 'S') return 3;
        if (m == 'D') return 2;
        return 1;  // P
    }

    // TODO #1: overload operator==
    // two coins are equal if same denomination AND year
    bool operator== (const Coin& other) const {
        return (denomination == other.denomination && year == other.year);
    }

    // TODO #2: overload operator<
    // a coin is less than another if its denomination is smaller
    bool operator< (const Coin& other) const {
        return (denomination < other.denomination);
    }

    // TODO #3: overload operator>
    // a coin is "greater than" another if it comes from a more prestigious mint
    // rank: W(4) > S(3) > D(2) > P(1)
    // use the mintRank() helper function to determine the rank of a mint
    bool operator> (const Coin& other) const {
        return (mintRank(mint) > mintRank(other.mint));
    }
    
};

int main() {
    Coin c1(0.25, 1965, 'P');
    Coin c2(0.10, 1982, 'D');
    Coin c3;
    c3.setDenomination(0.25);
    c3.setYear(1965);
    c3.setMint('D');
    
    c1.print();
    c2.print();
    c3.print();
    cout << endl;

    cout << "Equality check (operator==):\n";
    cout << "  c1 == c2 ? " << (c1 == c2 ? "Yes" : "No") << endl;
    cout << "  c1 == c3 ? " << (c1 == c3 ? "Yes" : "No") << endl << endl;

    cout << "Value comparison (operator<):\n";
    cout << "  Is c2 worth less than c1? " << (c2 < c1 ? "Yes" : "No") << endl;
    cout << "  Is c1 worth less than c3? " << (c1 < c2 ? "Yes" : "No") << endl;

    return 0;
}

/*
SAMPLE OUTPUT

$0.25          1965  P
$0.10          1982  D
$0.25          1965  D

Equality check (operator==):
  c1 == c2 ? No
  c1 == c3 ? Yes

Value comparison (operator<):
  Is c2 worth less than c1? Yes
  Is c1 worth less than c2? No
*/