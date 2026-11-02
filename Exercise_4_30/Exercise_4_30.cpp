#include <iostream>
using namespace std;

const int SIZE = 6;

void bucketSort(int a[], int size) {
    int bucket[10][SIZE];
    int count[10];

    int largest = a[0];

    for (int i = 1; i < size; i++) {
        if (a[i] > largest) {
            largest = a[i];
        }
    }

    int digits = 0;
    int number = largest;

    while (number > 0) {
        digits++;
        number = number / 10;
    }

    int divisor = 1;

    for (int pass = 0; pass < digits; pass++) {
        for (int i = 0; i < 10; i++) {
            count[i] = 0;
        }

        for (int i = 0; i < size; i++) {
            int digit = a[i] / divisor % 10;
            int position = count[digit];

            cout << digit << "digit";
            cout << "\n";
			cout << position << "position";

            bucket[digit][position] = a[i];
            count[digit]++;
        }

        int index = 0;

        for (int row = 0; row < 10; row++) {
            for (int column = 0; column < count[row]; column++) {
                a[index] = bucket[row][column];
                index++;
            }
        }

        if (pass < digits - 1) {
            divisor = divisor * 10;
        }
    }
}

int main() {
    int a[SIZE] = { 97, 3, 100, 25, 8, 42 };

    bucketSort(a, SIZE);

    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " ";
    }

    return 0;
}