#include <iostream>
#include "backpack.h"
#include <cstring>

using std::cout;
using std::endl;


int main() {

    Item lamp("lamp", 2, 3);
    Item knife("knife", 1.4, 0.4);
    Item cup("cup", 0.3, 4);

    Backpack myBackpack(4, 4);

    try {
        cout << "Add lamp...\n";
        myBackpack.add(lamp);
    } catch (WeightOverflow &e) {
        cout << e.what() << endl;
    }
    catch (VolumeOverflow &e) {
        cout << e.what() << endl;
    }

    cout << "Size: " << myBackpack.size() << ", ";
    cout << "Left volume: " << myBackpack.leftVolume() << ", ";
    cout << "Left weight: " << myBackpack.leftWeight() << endl;

    try {
        cout << "Add knife...\n";
        myBackpack.add(knife);
    } catch (WeightOverflow &e) {
        cout << e.what() << endl;
    } catch (VolumeOverflow &e) {
        cout << e.what() << endl;
    }

    cout << "Size: " << myBackpack.size() << ", ";
    cout << "Left volume: " << myBackpack.leftVolume() << ", ";
    cout << "Left weight: " << myBackpack.leftWeight() << endl;

    try
    {
        cout << "Add cup...\n";
        myBackpack.add(cup);
    }
    catch (WeightOverflow &e)
    {
        cout << e.what() << endl;
    }
    catch (VolumeOverflow &e)
    {
        cout << e.what() << endl;
    }

    cout << "Size: " << myBackpack.size() << ", ";
    cout << "Left volume: " << myBackpack.leftVolume() << ", ";
    cout << "Left weight: " << myBackpack.leftWeight() << endl;

    cout << "Get item at index 1 ...\n";
    cout << myBackpack[1].getName() << endl;

    return 0;
}