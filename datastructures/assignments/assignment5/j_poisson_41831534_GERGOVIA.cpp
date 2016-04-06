#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    long long int numberOfInhabitants, totalWork, counter;

    while (true) {
        totalWork = 0;
        counter   = 0;

        cin >> numberOfInhabitants;
        if (numberOfInhabitants == 0) return 0;

        long long int arrayOfInhabitants[numberOfInhabitants];
        for (int i = 0; i < numberOfInhabitants; i++) {
            cin >> arrayOfInhabitants[i];
        }

        for (int i = 1; i < numberOfInhabitants; i++) {
            arrayOfInhabitants[i] += arrayOfInhabitants[i - 1];
            totalWork += abs(arrayOfInhabitants[i - 1]);
        }

        cout << totalWork << endl;
    }

}
