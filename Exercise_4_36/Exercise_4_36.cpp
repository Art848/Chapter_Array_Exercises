#include <iostream>
using namespace std;

void printArray(int a[], int size) {
    if (size == 0) {
        return;
    }

    printArray(a, size - 1);

    cout << a[size - 1] << " ";
}

int main() {
    const int SIZE = 5;
    int a[SIZE] = { 2, 4, 6, 8, 10 };

    printArray(a, SIZE);

    return 0;
}