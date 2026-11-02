#include <iostream>
using namespace std;

int main() {
    const int SIZE = 20;
    int numbers[SIZE];
    int count = 0;
    int number;
    bool duplicate;

	int minimumNumber = 10;
    int maxmimumNumber = 100;

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter a number (10-100): ";
        cin >> number;

        if (number < minimumNumber || number > maxmimumNumber) {
            cout << "Invalid number.\n";
            i--;
            continue;
        }

        duplicate = false;

        for (int j = 0; j < count; j++) {
            if (numbers[j] == number) {
                duplicate = true;
                break;
            }
        }

        if (duplicate == false) {
            numbers[count] = number;
            count++;

            cout << "New number: " << number << endl;
        }
    }

    return 0;
}