#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));

	int countOfSums[13] = { 0 }; // Array to hold counts for sums 2 through 12

	for (int i = 0; i < 36000; i++) {
		int firstDice = 1 + rand() % 6;
		int secondDice = 1 + rand() % 6;

		int sum = firstDice + secondDice;
		countOfSums[sum]++;
	}

	for (int i = 2; i <= 12; i++) {
		cout << "Number of times sum equal to " << i  
			<< " repeated: " << countOfSums[i] << endl;
	}

}