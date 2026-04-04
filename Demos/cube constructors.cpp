#include <iostream>
using namespace std;

class Cube {
private:
    double width;
    double length;
    double height;
    
public:
    // parameter constructor
    Cube(double w, double l, double h) {
        width = w;
        length = l;
        height = h;
    }

    // default constructor
    Cube() {
        width = 1.0;
        length = 1.0;
        height = 1.0;
    }

    // setters and getters
    void setWidth(double w)    { width = w; }
    void setLength(double l)   { length = l; }
    void setHeight(double h)   { height = h; }
    double getWidth()          { return width; }
    double getLength()         { return length; }
    double getHeight()         { return height; }

    // print() method outputs the width, length, and height to the console
    // no parameters or return values
    void print() {
        cout << "Width: " << width << endl;
        cout << "Length: " << length << endl;
        cout << "Height: " << height << endl;
    }
    
    // getVolume() calculates the volume of a cube and returns the result
    // parameters: none
    // returns: the product of width, length, and height
    double getVolume() {
        return width * length * height;
    }
};


int main() {
    // declarations and assignments
    Cube shape1(12,14,8);

    cout << "-Cube data-\n";
    shape1.print();
    double volume = shape1.getVolume();
    cout << "Volume: " << volume << endl;
    return 0;
}