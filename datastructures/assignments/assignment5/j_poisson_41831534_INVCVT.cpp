#include <iostream>

using namespace std;

long long int merge(long long int array[], long long int left,
        long long int middle, long long int right) {
    long long int temporaryArray[200000];
    long long int count = 0;
    long long int leftCopy1 = left;
    long long int leftCopy2 = left;
    long long int middleCopy = middle;

    while ((leftCopy1 <= middle - 1) && (middleCopy <= right)) {
        if (array[leftCopy1] <= array[middleCopy]) {
            temporaryArray[leftCopy2] = array[leftCopy1];
            leftCopy1++; leftCopy2++;
        } else {
            temporaryArray[leftCopy2] = array[middleCopy];
            count = count + (middle - leftCopy1);
            leftCopy2++; middleCopy++;
        }
    }

    while (leftCopy1 <= middle -1) {
        temporaryArray[leftCopy2] = array[leftCopy1];
        leftCopy1++; leftCopy2++;
    }

    while (middleCopy <= right) {
        temporaryArray[leftCopy2] = array[middleCopy];
        leftCopy2++; middleCopy++;
    }

    for (int i = left; i <= right; i++) {
        array[i] = temporaryArray[i];
    }

    return count;
}

long long int mergeSort(long long int array[], long long int left,
        long long int right) {
    if (right > left) {
        long long int middle = (left + right) / 2;
        long long int x = mergeSort(array, left, middle);
        long long int y = mergeSort(array, middle + 1, right);
        long long int z = merge(array, left, middle + 1, right);
        return x + y + z;
    }
    return 0;
}


int main() {
    long long int numberOfTestCases, numberOfInputs;
    long long int arrayOfInputs[200000];

    cin >> numberOfTestCases;

    while (numberOfTestCases--) {
        cin >> numberOfInputs;

        for (int i = 0; i < numberOfInputs; i++) {
            cin >> arrayOfInputs[i];
        }

        long long int numberOfInversions = mergeSort(arrayOfInputs, 0,
                numberOfInputs-1);
        cout << numberOfInversions << endl;
    }
    return 0;
}
