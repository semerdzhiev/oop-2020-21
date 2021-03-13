#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;


    void print() {
        cout<< x<< " "<< y<< endl;
    }

    // method to return distance to origin
    double distanceToOrigin() {
        return sqrt(x*x+y*y);
    }

    // method to return distance to another point
    double distanceToAnotherPiont(Point& p2){
        double dx = abs(x - p2.x), dy = abs(y - p2.y);
        return sqrt(dx*dx + dy*dy);
    }

};

int main() {
    Point p{3, 4};
    Point p2{6, 8};

    p.print();
    cout<< p.distanceToAnotherPiont(p2)<< endl;
}
