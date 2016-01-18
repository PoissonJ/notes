#include <iostream>

using namespace std;

int main() {
    int array_size;
    cin >> array_size;

    int arr [array_size];

    // Handle input
    for (int i = 0; i < array_size; i++) {
        cin >> arr[i];
    }

    // Insertion sort
    for (int i = 1; i < array_size; i++) {
        int current_value = arr[i];
        int j = i - 1;

        while (j >= 0 && current_value < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current_value;
    }

    // Pring array
    for (int i = 0; i < array_size; i++) {
        cout << arr[i] << endl;
    }
}
