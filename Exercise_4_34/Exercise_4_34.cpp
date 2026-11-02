#include <iostream>
using namespace std;

int binarySearch(int a[], int key, int first, int last) {
    if (first > last) {
        return -1;
    }

    int middle = first + (last - first) / 2;

    if (a[middle] == key) {
        return middle;
    }

    if (key < a[middle]) {
        return binarySearch(a, key, first, middle - 1);
    }
    else {
        return binarySearch(a, key, middle + 1, last);
    }
}

int main() {
    const int SIZE = 7;
    int a[SIZE] = { 2, 5, 8, 12, 16, 23, 38 };

    int numberToFind;

    cout << "Enter the number to find: ";
    cin >> numberToFind;

    int result = binarySearch(a, numberToFind, 0, SIZE - 1);

    if (result == -1) {
        cout << "Number not found";
    }
    else {
        cout << "Found at index: " << result;
    }

    return 0;
}