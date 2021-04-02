#include <iostream>
#include "time.h"

using std::cout;
using std::endl;

int main() {
    Time time(21, 45, LONDON);

    cout << time.getMoscowTime() << endl;
    cout << time.getSofiaTime() << endl;
    cout << time.getLondonTime() << endl;
    cout << time.getNewYorkTime() << endl;
}
