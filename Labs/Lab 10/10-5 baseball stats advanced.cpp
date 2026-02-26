//LAB 10-5
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int WIDTH1 = 11, WIDTH2 = 6, PLAYERS = 20, LINES = 80;

int main() {
    //Getting our input file object
    string filename = "252-lab-10-4-files-input.txt";
    ifstream fin(filename);
    
    //Arrays all sized to the number of players
    string first[PLAYERS];
    string last[PLAYERS];
    int homeruns[PLAYERS] = {0};
    double bat_avg[PLAYERS] = {0};
    
    //Data to be calculated based on lab requirements
    string highest_hr, highest_bat;
    int total_homeruns, avg_homeruns;
    double tot_bat_avg, avg_bat_avg;
    
    //Variables used to find max element in the arrays
    int temp1 = 0;
    double temp2 = 0;
    int high_hr_index, high_bat_index;

    //Loop that stores data in multiple different arrays
    for (int i = 0; i < PLAYERS; i++) {
        fin >> last[i];
        fin >> first[i];
        fin >> homeruns[i];
        fin >> bat_avg[i];
    }
    fin.close();
    
    //Console headers for labeling data
    cout << "--------Individual Player STATS--------" << endl;
    cout << left << setw(WIDTH1) << "[First]" << "[Last]"
         << "   [Homeruns]" << "[Bat Avg]" << endl;
    
    //Traversing all arrays simulatenously to show file contents
    for (int i = 0; i < PLAYERS; i++) {
        cout << left << setw(WIDTH1) << first[i]
             << setw(WIDTH1) << last[i] << "\t"
             << setw(WIDTH2) << homeruns[i] << "\t"
             << setw(WIDTH2) << bat_avg[i] << endl;
    }
    
    //Calculating totals 
    for (int i = 0; i < PLAYERS; i++) {
        total_homeruns += homeruns[i];
        tot_bat_avg += bat_avg[i];
    }
    
    //Calculating averages
    avg_homeruns = total_homeruns / PLAYERS;
    avg_bat_avg = tot_bat_avg / PLAYERS;
    
    //Display for average stats
    cout << endl << "----STATS for ALL Players----" << endl;
    cout << "Average Homeruns: \t" << avg_homeruns << endl;
    cout << fixed << setprecision(3) //3 decimal places to match file
         << "Average Batting Avg: \t" << avg_bat_avg << endl;
    
    //Loop that finds the index for the player with highest homeruns
    for (int i = 0; i < PLAYERS; i++) {
        if (temp1 < homeruns[i]) {
            high_hr_index = i;
            temp1 = homeruns[i];
        }
    }
    
    //Loop that finds the index for the player with highest bat avg
    for (int i = 0; i < PLAYERS; i++) {
        if (temp2 < bat_avg[i]) {
            high_bat_index = i;
            temp2 = bat_avg[i];
        }
    }
    
    //Loop that uses the previous indexes to identify two players
    for (int i = 0; i < PLAYERS; i++) {
        if (i == high_hr_index) {
            highest_hr = first[i] + " " + last[i];
        }
        if (i == high_bat_index) {
            highest_bat = first[i] + " " + last[i];
        }
    }
    
    //Displaying the results from the three previous loops
    cout << "Highest Homeruns: \t" << highest_hr << endl;
    cout << "Highest Batting Avg: \t" << highest_bat << endl;
    
    return 0;
}