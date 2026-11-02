#include <iostream>
using namespace std;

int main() {
    const int SIZE = 1000;
    int prime[SIZE];

    for (int i = 0; i < SIZE; i++) {
        prime[i] = 1;
    }

    prime[0] = 0;
    prime[1] = 0;

    for (int number = 2; number < SIZE; number++) {
        if (prime[number] == 1) {
            for (int multiple = number * 2; multiple < SIZE; multiple += number) {
                prime[multiple] = 0;
            }
        }
    }

    cout << "Prime numbers from 2 to 999:\n";

    for (int number = 2; number < SIZE; number++) {
        if (prime[number] == 1) {
            cout << number << " ";
        }
    }

    cout << endl;

    return 0;
}