#include <iostream>
using namespace std;

int linearSearch(int a[], int size, int number, int index) {
    if (index >= size) {
        return -1;
    }

    if (a[index] == number) {
        return index;
    }

    return linearSearch(a, size, number, index + 1);
}

int main() {
    const int SIZE = 5;
    int a[SIZE] = { 7, 3, 9, 1, 5 };

    int numberToFind;

    cout << "Enter the number to find: ";
    cin >> numberToFind;

    int result = linearSearch(a, SIZE, numberToFind, 0);

    if (result == -1) {
        cout << "Number not found";
    }
    else {
        cout << "Found at index: " << result;
    }

    return 0;
}