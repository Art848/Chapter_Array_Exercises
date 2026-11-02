#include <iostream>
using namespace std;

void selectionSort(int a[], int size, int start) {
    if (start >= size - 1) {
        return;
    }

    int smallest = start;

    for (int i = start + 1; i < size; i++) {
        if (a[i] < a[smallest]) {
            smallest = i;
        }
    }

    int hold = a[start];
    a[start] = a[smallest];
    a[smallest] = hold;

    selectionSort(a, size, start + 1);
}

int main() {
    const int SIZE = 5;
    int a[SIZE] = { 7, 3, 9, 1, 5 };

    selectionSort(a, SIZE, 0);

    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " ";
    }

    return 0;
}