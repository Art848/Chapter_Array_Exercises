#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDice() {
    int firstDice = 1 + rand() % 6;
    int secondDice = 1 + rand() % 6;
    int sum = firstDice + secondDice;

    return sum;
}

int main() {
    srand(time(0));

    const int GAMES = 1000;
    const int LAST_ROLL = 20;
    const int AFTER_LAST = 21;
    const int SIZE = 22;

	const int WINNING_NUMBER1 = 7;
	const int WINNING_NUMBER2 = 11;

	const int LOSING_NUMBER1 = 2;
	const int LOSING_NUMBER2 = 3;
	const int LOSING_NUMBER3 = 12;

	const int LOSING_POINT1 = 7;

    int wins[SIZE] = { 0 };
    int losses[SIZE] = { 0 };

    int totalWins = 0;
    int totalRolls = 0;

    for (int game = 0; game < GAMES; game++) {
        int sum = rollDice();
        int rolls = 1;
        bool won = false;

        if (sum == WINNING_NUMBER1 || sum == WINNING_NUMBER2) {
            won = true;
        }
        else if (sum == LOSING_NUMBER1 || sum == LOSING_NUMBER2 || sum == LOSING_NUMBER3) {
            won = false;
        }
        else {
            int point = sum;
            bool finished = false;

            while (finished == false) {
                sum = rollDice();
                rolls++;

                if (sum == point) {
                    won = true;
                    finished = true;
                }
                else if (sum == LOSING_POINT1) {
                    won = false;
                    finished = true;
                }
            }
        }

        totalRolls += rolls;

        int index = rolls;

        if (index > LAST_ROLL) {
            index = AFTER_LAST;
        }

        if (won == true) {
            wins[index]++;
            totalWins++;
        }
        else {
            losses[index]++;
        }
    }

    cout << "Roll\tWins\tLosses\tWin %\n";

    for (int i = 1; i <= AFTER_LAST; i++) {
        if (i == AFTER_LAST) {
            cout << "20+";
        }
        else {
            cout << i;
        }

        cout << '\t' << wins[i]
            << '\t' << losses[i] << '\t';

        int finishedGames = wins[i] + losses[i];

        if (finishedGames > 0) {
            double percent = wins[i] * 100.0 / finishedGames;
            cout << percent;
        }
        else {
            cout << "-";
        }

        cout << '\n';
    }

    double winPercent = totalWins * 100.0 / GAMES;
    double averageRolls = totalRolls * 1.0 / GAMES;

    cout << "Overall win percentage: " << winPercent << "%\n";

    cout << "Average rolls per game: " << averageRolls << '\n';

    return 0;
}