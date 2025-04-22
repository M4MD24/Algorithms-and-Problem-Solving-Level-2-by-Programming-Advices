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

struct DigitCount {
    int zero,
        one,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine;
};

DigitCount frequencyCountAllDigits(int number) {
    DigitCount digitCount = {};
    while (number != 0) {
        switch (const int DIGIT = number % 10) {
        case 0: digitCount.zero++;
            break;
        case 1: digitCount.one++;
            break;
        case 2: digitCount.two++;
            break;
        case 3: digitCount.three++;
            break;
        case 4: digitCount.four++;
            break;
        case 5: digitCount.five++;
            break;
        case 6: digitCount.six++;
            break;
        case 7: digitCount.seven++;
            break;
        case 8: digitCount.eight++;
            break;
        default: digitCount.nine++;
        }
        number /= 10;
    }
    return digitCount;
}

void printAllDigits(const DigitCount DIGIT_COUNT) {
    const string LABEL_DELIMITER = ": ";
    if (DIGIT_COUNT.zero)
        cout << 0 << LABEL_DELIMITER << DIGIT_COUNT.zero << endl;
    if (DIGIT_COUNT.one)
        cout << 1 << LABEL_DELIMITER << DIGIT_COUNT.one << endl;
    if (DIGIT_COUNT.two)
        cout << 2 << LABEL_DELIMITER << DIGIT_COUNT.two << endl;
    if (DIGIT_COUNT.three)
        cout << 3 << LABEL_DELIMITER << DIGIT_COUNT.three << endl;
    if (DIGIT_COUNT.four)
        cout << 4 << LABEL_DELIMITER << DIGIT_COUNT.four << endl;
    if (DIGIT_COUNT.five)
        cout << 5 << LABEL_DELIMITER << DIGIT_COUNT.five << endl;
    if (DIGIT_COUNT.six)
        cout << 6 << LABEL_DELIMITER << DIGIT_COUNT.six << endl;
    if (DIGIT_COUNT.seven)
        cout << 7 << LABEL_DELIMITER << DIGIT_COUNT.seven << endl;
    if (DIGIT_COUNT.eight)
        cout << 8 << LABEL_DELIMITER << DIGIT_COUNT.eight << endl;
    if (DIGIT_COUNT.nine)
        cout << 9 << LABEL_DELIMITER << DIGIT_COUNT.nine;
}

int main() { printAllDigits(frequencyCountAllDigits(readPositiveNumber())); }