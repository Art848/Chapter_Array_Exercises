#include <iostream>
using namespace std;

int recursiveMinimum(int a[], int size) {
    if (size == 1) {
        return a[0];
    }

    int smallest = recursiveMinimum(a, size - 1);

    if (a[size - 1] < smallest) {
        smallest = a[size - 1];
    }

    return smallest;
}

int main() {
    const int SIZE = 5;
    int a[SIZE] = { 7, 3, 9, 1, 5 };

    int result = recursiveMinimum(a, SIZE);

    cout << "Smallest number: " << result;

    return 0;
}