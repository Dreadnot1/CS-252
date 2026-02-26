//LAB 10-4
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int WIDTH = 11, PLAYERS = 20;

int main() {
    string filename = "252-lab-10-4-files-input.txt";
    ifstream fin(filename);
    
    //Player information to read from the file
    string last, first;
    int homeruns, total_homeruns, avg_homeruns;
    double bat_avg, tot_bat_avg, avg_bat_avg;

    //Display for data
    while (fin >> last >> first >> homeruns >> bat_avg) {
        cout << setw(WIDTH) << right << first << " " << last << " "
             << "\t" << homeruns << "\t" << bat_avg << endl;
        total_homeruns += homeruns;
        tot_bat_avg += bat_avg;
    }

    fin.close();
    
    //Some quick calculations for averages
    avg_homeruns = total_homeruns / PLAYERS;
    avg_bat_avg = tot_bat_avg / PLAYERS;
    
    //Display for average stats
    cout << endl << "--STATS for ALL Players--" << endl;
    cout << "Average Homeruns: \t" << avg_homeruns << endl;
    cout << fixed << setprecision(3) //3 decimal places to match file
         << "Average Batting Avg: \t" << avg_bat_avg << endl;
    
    return 0;
}