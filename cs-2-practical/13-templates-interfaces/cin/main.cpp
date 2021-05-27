#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{

    string names;
    vector<string> split;
    getline(cin, names);

    cout << names << endl;
    string delimiter = " ";
    string token = names.substr(0, names.find(delimiter));
    cout << token << endl;
    return 0;
}
