#include <iostream>
#include <cmath>

using namespace std;

//Function prototype
double calc_distance(double, double, double, double);

int main() {
    double x1 = 17.3, y1= 5.5, x2 = 9.7, y2 = 3.2;
    double result;
    
    //Function call
    result = calc_distance(x1, y1, x2, y2);
    cout << "Distance between points: " << result;
    
    return 0;
}

//Function definition
double calc_distance(double x1, double y1, double x2, double y2) {
    double horizontal, vertical, sum, distance;
    
    //Uses the distance formula with provided (x,y) coordinates
    horizontal = pow((x2-x1), 2);
    vertical = pow((y2-y1), 2);
    sum = horizontal + vertical;
    distance = sqrt(sum);
    
    return distance;
}