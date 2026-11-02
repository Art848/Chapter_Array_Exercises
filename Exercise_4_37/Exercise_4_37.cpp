#include <iostream>
using namespace std;

void stringReverse(char text[], int index = 0) {
    if (text[index] == '\0') {
        return;
    }

    stringReverse(text, index + 1);

    cout << text[index];
}

int main() {
	const int maxLength = 100;
    char text[maxLength];

    cout << "Enter text: ";
    cin.getline(text, maxLength);

    stringReverse(text);

    cout << endl;

    return 0;
}