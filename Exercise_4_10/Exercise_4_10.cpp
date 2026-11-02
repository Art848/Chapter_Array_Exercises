#include <iostream>
using namespace std;

int main() {
    const int SIZE = 9;
    int counts[SIZE] = { 0 };

    int numberOfSalespeople;
    int salary;
    int index;
    int lower;
    int upper;

    double sales;
    double commission;
    double totalSalary;
    double baseSalary = 200;
    double commissionRate = 0.09;

    cout << "How many salespeople? ";
    cin >> numberOfSalespeople;

    for (int i = 0; i < numberOfSalespeople; i++) {
        cout << "Enter weekly sales: ";
        cin >> sales;

        if (sales < 0) {
            cout << "Enter a positive amount or zero.\n";
            i--;
            continue;
        }

        commission = sales * commissionRate;
        totalSalary = baseSalary + commission;
        salary = static_cast<int>(totalSalary);

        index = salary / 100;
        index = index - 2;

        if (index > 8) {
            index = 8;
        }

        counts[index]++;
    }

    cout << "\nSalary range: Number of salespeople\n";

    for (int i = 0; i < SIZE - 1; i++) {
        lower = 200 + i * 100;
        upper = lower + 99;

        cout << lower << "-" << upper << ": "
            << counts[i] << '\n';
    }

    cout << "1000 and over: " << counts[8] << '\n';

    return 0;
}