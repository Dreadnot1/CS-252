#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 10, b = 15, c =20;
    int d = 1000, e = 1020, f = 1040;
    string name1 = "Joe Black", name2 = "Jane Smith";
    double sales1 = 200.95, sales2 = 100.50;
    double result = 100.4258353;
    
    //Default behavior: 6 digits
    cout << result << endl;
    cout << fixed << result << endl;
    cout << fixed << setprecision(5) << result << endl;
    cout << scientific << result << endl;
    cout << setw(5) << a << setw(5) << b << setw(5) << c << endl;
    cout << setw(5) << d << setw(5) << e << setw(5) << f << endl;
    cout << endl;
    
    //setw changes to right justification
    cout << left;
    cout << setw(15) << name1 << right << setw(15) << name2;
    
    /* cout manipulators
    left, right, setw(), setprecision(), fixed, scientific
    */

    return 0;
}