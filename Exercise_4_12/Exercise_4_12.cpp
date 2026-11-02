#include <iostream>
using namespace std;

int main()
{
	// a) Initialize the 10 elements of integer array counts to zero. 
	int counts[10] = { 0 };

	// b) Add 1 to each of the 15 elements of integer array bonus.
	int bonus[15] = { 0 };

	for (int i = 0; i < 15; i++) {
		bonus[i] += 1;
	}

	// c) Read 12 values for double array monthlyTemperatures from the keyboard.
	double  monthlyTemperatures[12];

	for (int i = 0; i < 12; i++) {
		cout << "Enter temperature for month " << i + 1 << ": ";
		cin >> monthlyTemperatures[i];
	}

	// d) Print the 5 values of integer array bestScores in column format.
	int bestScores[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		cout << bestScores[i] << '\n';
	}

}

