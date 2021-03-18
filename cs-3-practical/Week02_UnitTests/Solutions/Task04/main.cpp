#include <iostream>
#include "runner.h"

using std::cin;
using std::cout;
using std::endl;

const int MAX_NUMBER_PARTICIPANTS = 1000;

void printSlowestRunner(Runner runnersList[MAX_NUMBER_PARTICIPANTS], int n)
{
    int slowestRunnerIndex = 0;
    double slowestPace = runnersList[slowestRunnerIndex].getPace();

    for (int i = 1; i < n; i++)
    {
        if (slowestPace > runnersList[i].getPace())
        {
            slowestPace = runnersList[i].getPace();
            slowestRunnerIndex = i;
        }
    }

    cout << "Slowest runner is " << runnersList[slowestRunnerIndex].name << " " << runnersList[slowestRunnerIndex].family << endl;
}

int main()
{
    int n, indexA, indexB;
    Runner runnersList[MAX_NUMBER_PARTICIPANTS];

    cout << "Number of runners: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        runnersList[i].read();
    }

    printSlowestRunner(runnersList, n);

    cout << "Enter index of first runner: ";
    cin >> indexA;
    cout << "Enter index of second runner: ";
    cin >> indexB;
    cout << runnersList[indexA - 1].beatNtimes(&runnersList[indexB - 1]) << endl;

    for (int i = 0; i < n; i++)
    {
        runnersList[i].clean();
    }

    return 0;
}