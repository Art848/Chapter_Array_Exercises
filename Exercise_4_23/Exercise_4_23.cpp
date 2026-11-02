#include <iostream>
using namespace std;

int main() {
    const int SIZE = 20;
    int floor[SIZE][SIZE] = { 0 };

    int commands[] = {
        2,
        5, 5,
        3,
        5, 5,
        3,
        5, 5,
        3,
        5, 5,
        1,
        6,
        9
    };

    int row = 0;
    int column = 0;

    // 0 = right, 1 = down, 2 = left, 3 = up
    int direction = 0;

    int pen = 0;  // 0 = up, 1 = down
    int index = 0;
    int command;
    int steps;
    int nextRow;
    int nextColumn;

    while (commands[index] != 9) {
        command = commands[index];
        index++;

        if (command == 1) {
            pen = 0;
        }

        else if (command == 2) {
            pen = 1;
        }

        else if (command == 3) {
            direction++;

            if (direction == 4) {
                direction = 0;
            }
        }

        else if (command == 4) {
            direction--;

            if (direction == -1) {
                direction = 3;
            }
        }

        else if (command == 5) {
            steps = commands[index];
            index++;

            if (pen == 1) {
                floor[row][column] = 1;
            }

            for (int i = 0; i < steps; i++) {
                nextRow = row;
                nextColumn = column;

                if (direction == 0) {
                    nextColumn++;
                }
                else if (direction == 1) {
                    nextRow++;
                }
                else if (direction == 2) {
                    nextColumn--;
                }
                else {
                    nextRow--;
                }

                if (nextRow < 0 || nextRow >= SIZE ||
                    nextColumn < 0 || nextColumn >= SIZE) {
                    break;
                }

                row = nextRow;
                column = nextColumn;

                if (pen == 1) {
                    floor[row][column] = 1;
                }
            }
        }

        else if (command == 6) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (floor[i][j] == 1) {
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    }
                }

                cout << endl;
            }
        }

        else if (command == 7) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    floor[i][j] = 0;
                }
            }
        }
    }

    return 0;
}