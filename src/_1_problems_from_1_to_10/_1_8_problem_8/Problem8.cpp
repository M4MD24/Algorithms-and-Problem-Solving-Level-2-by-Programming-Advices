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

short readDigit() {
    short digit;
    do {
        cout << "Enter digit:" << endl;
        cin >> digit;
    } while (digit < 0 || digit > 9);
    return digit;
}

int frequencyCount(
    int number,
    const short DIGIT
) {
    int frequencyCount = 0;
    while (number != 0) {
        const int REMAINDER = number % 10;
        if (REMAINDER == DIGIT)
            ++frequencyCount;
        number /= 10;
    }
    return frequencyCount;
}

int main() {
    const int NUMBER = readPositiveNumber();
    const short DIGIT = readDigit();
    cout << "Digit " << DIGIT << " Frequency is " << frequencyCount(NUMBER, DIGIT) << " Times(s)";
}