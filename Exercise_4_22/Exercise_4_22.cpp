#include <iostream>
using namespace std;

int main() {
    const int NUM_PRODUCTS = 5;
    const int NUM_SELLERS = 4;
    double sales[NUM_PRODUCTS][NUM_SELLERS] = { 0 };

    int slips_count;
    int person;
    int product;
    double amount;
    double sum;

    cout << "Enter number of slips: ";
    cin >> slips_count;

    for (int i = 0; i < slips_count; i++) {
        cout << "Enter salesperson number (1-4), 0 to finish: ";
        cin >> person;

        if (person == 0) {
            break;
        }

        if (person < 1 || person > NUM_SELLERS) {
            cout << "Invalid salesperson.\n";
            continue;
        }

        cout << "Enter product number (1-5): ";
        cin >> product;

        if (product < 1 || product > NUM_PRODUCTS) {
            cout << "Invalid product.\n";
            continue;
        }

        cout << "Enter sales amount: ";
        cin >> amount;

        if (amount < 0) {
            cout << "Invalid amount.\n";
            continue;
        }

        sales[product - 1][person - 1] += amount;
    }

    cout << "\nProduct\tSeller1\tSeller2\tSeller3\tSeller4\tTotal\n";

    for (int i = 0; i < NUM_PRODUCTS; i++) {
        cout << i + 1 << "\t";
        sum = 0;

        for (int j = 0; j < NUM_SELLERS; j++) {
            cout << sales[i][j] << "\t";
            sum += sales[i][j];
        }

        cout << sum << endl;
    }

    cout << "Total\t";

    for (int j = 0; j < NUM_SELLERS; j++) {
        sum = 0;

        for (int i = 0; i < NUM_PRODUCTS; i++) {
            sum += sales[i][j];
        }

        cout << sum << "\t";
    }

    cout << endl;

    return 0;
}