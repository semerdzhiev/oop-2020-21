#include <iostream>
#include "horo.h"

using std::cout;
using std::endl;

int main()
{
    char mockName[32] = "Paydushko";
    char mockMeter[32] = "5/8";
    char mockRegion[32] = "Northern region";
    
    ImmutableHoro paydushko(mockName, mockMeter, mockRegion);

    cout << paydushko.getName() << " (" << paydushko.getMeter() << ") - " << paydushko.getRegion() << endl;

    return 0;
}
