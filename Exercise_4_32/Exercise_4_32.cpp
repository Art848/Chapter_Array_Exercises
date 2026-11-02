#include <iostream>
using namespace std;

bool testPalindrome(char text[], int first, int last) {
    if (first >= last) {
        return true;
    }

    if (text[first] != text[last]) {
        return false;
    }

    return testPalindrome(text, first + 1, last - 1);
}

int main() {
    const int maxLength = 100;
    char text[maxLength];
    char clean[maxLength];
    int count = 0;

    cout << "Enter text: ";
    cin.getline(text, maxLength);

    for (int i = 0; text[i] != '\0'; i++) {
        char letter = text[i];

        if ((letter >= 'a' && letter <= 'z') ||
            (letter >= 'A' && letter <= 'Z') ||
            (letter >= '0' && letter <= '9')) {

            clean[count] = letter;
            count++;
        }
    }

    clean[count] = '\0';

    bool result = testPalindrome(clean, 0, count - 1);

    if (result == true) {
        cout << "Palindrome";
    }
    else {
        cout << "Not a palindrome";
    }

    return 0;
}