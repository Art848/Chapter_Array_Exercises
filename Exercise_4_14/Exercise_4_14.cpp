#include <iostream>
using namespace std;

void mode(int[], int[], const int);
void bubbleSort(int[], int);
void median(int[], int);

int main()
{
    
    const int RESPONSE_SIZE = 100;

    int frequency[10] = { 0 };

    int response[RESPONSE_SIZE] = {
        6, 7, 8, 9, 7, 8, 9, 5,6, 7, 8, 9, 7, 8, 9, 8,6, 1, 8, 7,1, 8, 9, 8,
        5, 6, 7, 2,7, 8, 9, 6, 7, 4, 4, 2,4, 5, 6, 1,4,1,8, 7, 8,9, 8, 7,
        3, 9, 8, 9, 8, 9, 8, 7, 9, 9, 8, 9,5, 3, 9, 8, 9, 8,9, 3, 8,6, 5, 7,
        9, 8,7,7,8,7,4,9,7,8,4,2,4,3,8, 9,7, 8,8, 9,8, 9,9, 9,9, 9, 9,1};

    mode(frequency, response, RESPONSE_SIZE);
    median(response, RESPONSE_SIZE);

    return 0;
}

void mode(int frequency[], int answer[], const int size)
{
    int largest = 0;

    for (int i = 0; i < 10; i++) {
        frequency[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        frequency[answer[i]]++;
    }

    for (int i = 1; i < 10; i++) {
        if (frequency[i] > largest) {
            largest = frequency[i];
        }
    }

    cout << "Mode: ";

    for (int i = 1; i < 10; i++) {
        if (frequency[i] == largest) {
            cout << i << " ";
        }
    }

    cout << endl;
}

void bubbleSort(int a[], int size) {
    int hold;
    // swapped 
    // it indicates whether a swap took place
    bool swapped;

    for (int pass = 1; pass < size; pass++) {
        swapped = false;

        // size - pass 
        // With each pass, the number of comparisons decreases by one.
        for (int i = 0; i < size - pass; i++) {

            if (a[i] > a[i + 1]) {
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;

                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

void median(int response[], int size) {
    bubbleSort(response, size);

    int middle = size / 2;
    double averageOfTwoMiddleElements = (response[middle - 1] + response[middle]) / 2.0;
    double result;

    if (size % 2 == 0) {
        result = averageOfTwoMiddleElements;
        cout << result;
    }
    else {
        result = response[middle];
    }

    cout << "Median: " << result << endl;
}