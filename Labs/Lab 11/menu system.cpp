#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 5, WIDTH1 = 22, WIDTH2 = 4, WIDTH3 = 6, COLUMNS = 4;

int main()
{
    double prices[SIZE] = {5.99, 3.50, 2.78, 7.99, 10.00};
    string items[SIZE] = {
        "Saturn Snowcones",
        "Supernova Poprocks",
        "Galactic Bubbleyum",
        "Dark Matter Chocolate",
        "Blueberry Anti-Donuts"
    };
    int user_choice, user_display;
    double subtotal;
    
    do {
        cout << "===== MENU =====" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << fixed << setprecision(2)
                 << i+1 << ". " << left << setw(WIDTH1) << items[i]
                 << setw(WIDTH2) << right << "$" 
                 << setw(WIDTH3) << prices[i] << endl;
        } //for loop to traverse items & prices arrays for menu
        cout << "6. " << "Checkout" << endl;
        cout << "================" << endl;
        cout << "Enter your choice: ";
        cin >> user_choice;
        user_display = user_choice-1; //used for proper indexing
        
        //Switch statements don't need interior braces
        switch (user_choice) {
            case 1:
                cout << prices[user_display] << " added to subtotal!" << endl;
                subtotal += prices[user_display];
                break; //escapes from the containing control structure
            case 2:
                cout << prices[user_display] << " added to subtotal!" << endl;
                subtotal += prices[user_display];
                break;
            case 3:
                cout << prices[user_display] << " added to subtotal!" << endl;
                subtotal += prices[user_display];
                break;
            case 4:
                cout << prices[user_display] << " added to subtotal!" << endl;
                subtotal += prices[user_display];
                break;
            case 5:
                cout << prices[user_display] << " added to subtotal!" << endl;
                subtotal += prices[user_display];
                break;
            case 6:
                cout << endl << fixed << setprecision(2) 
                     << "TOTAL DUE: $" << subtotal << endl;
                break;
            default:
                cout << "Please select 1-6." << endl;
                cout << "Returning to main menu." << endl;
        }
        
    } while (user_choice != 6);

    return 0;
}