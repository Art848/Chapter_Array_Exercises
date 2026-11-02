#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    const int HALF = 5;

    int seats[SIZE] = { 0 };
    int reserved = 0;
    int choice;
    int start;
    int end;
    int seat;
    char answer;

    while (reserved < SIZE) {
        cout << "\n1. First Class\n";
        cout << "2. Economy\n";
        cout << "Choose a class: ";
        cin >> choice;

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice.\n";
            continue;
        }

        if (choice == 1) {
            start = 0;
            end = HALF;
        }
        else {
            start = HALF;
            end = SIZE;
        }

        seat = -1;

        for (int i = start; i < end; i++) {
            if (seats[i] == 0) {
                seat = i;
                break;
            }
        }

        if (seat == -1) {
            cout << "This class is full.\n";
            cout << "Accept a seat in the other class? (y/n): ";
            cin >> answer;

            if (answer != 'y' && answer != 'Y') {
                cout << "Next flight leaves in 3 hours.\n";
                continue;
            }

            if (choice == 1) {
                start = HALF;
                end = SIZE;
            }
            else {
                start = 0;
                end = HALF;
            }

            for (int i = start; i < end; i++) {
                if (seats[i] == 0) {
                    seat = i;
                    break;
                }
            }
        }

        if (seat != -1) {
            seats[seat] = 1;
            reserved++;

            cout << "\nBoarding Pass\n";
            cout << "Seat: " << seat + 1 << '\n';

            if (seat < HALF) {
                cout << "Class: First Class\n";
            }
            else {
                cout << "Class: Economy\n";
            }
        }
    }

    cout << "\nThe plane is full.\n";
    cout << "Next flight leaves in 3 hours.\n";

    return 0;
}