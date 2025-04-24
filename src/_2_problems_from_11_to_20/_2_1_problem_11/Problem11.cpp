#include <iostream>
using namespace std;

int readPositiveNumber() {
    int number;
    do {
        cout << "Enter positive number:" << endl;
        cin >> number;
    } while (number < 1);
    return number;
}

enum NumberType {
    NotPalindrome = 0,
    Palindrome = 1
};

int reverseNumber(int number) {
    int reversedNumber = 0;

    while (number != 0) {
        const int REMAINDER = number % 10;
        reversedNumber = reversedNumber * 10 + REMAINDER;
        number /= 10;
    }

    return reversedNumber;
}

NumberType isPalindrome(int number) {
    if (
        number < 0 ||
        (
            number % 10 == 0 &&
            number != 0
        )
    )
        return NotPalindrome;

    int reversedHalf = 0;
    while (number > reversedHalf) {
        reversedHalf = reversedHalf * 10 + number % 10;
        number /= 10;
    }

    if (number == reversedHalf || number == reversedHalf / 10)
        return Palindrome;
    return NotPalindrome;
}

void printStatus(const NumberType STATUS) {
    cout << "Is";
    if (STATUS == NotPalindrome)
        cout << "n't";
    cout << " Palindrome";
}

int main() { printStatus(isPalindrome(readPositiveNumber())); }