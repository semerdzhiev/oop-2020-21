#include <iostream>
#include "pace.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Pace p1;
    cout << "Default speed was " << p1.getSpeed() << " km/h (";
    p1.printTempo();
    cout << ")\n";

    double speed;
    cout << "Enter speed:" << endl;
    cin >> speed;
    Pace p2(speed);
    cout << "Entered speed was " << p2.getSpeed() << "km/h (";
    p2.printTempo();
    cout << ")\n";

    int minutes, seconds;
    cout << "Enter tempo:" << endl;
    cin >> minutes >> seconds;
    Pace p3(minutes, seconds);
    cout << "Entered speed was " << p3.getSpeed() << "km/h (" << p3.getTempo() << ")\n";

    return 0;
}