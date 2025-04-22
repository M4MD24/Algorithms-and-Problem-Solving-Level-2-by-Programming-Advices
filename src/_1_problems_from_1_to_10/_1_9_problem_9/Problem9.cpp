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

void calculateFrequencyCountAllDigits(
    int number,
    int frequencyCountAllDigits[]
) {
    while (number != 0) {
        const int DIGIT = number % 10;
        ++frequencyCountAllDigits[DIGIT - 1];
        number /= 10;
    }
}

void printAllDigits(const int NUMBER) {
    int frequencyCountAllDigits[10] = {};
    calculateFrequencyCountAllDigits(
        NUMBER,
        frequencyCountAllDigits
    );

    for (int counter = 0; counter <= 9; ++counter) {
        const int CURRENT_FREQUENCY_COUNT_DIGIT = frequencyCountAllDigits[counter];
        if (CURRENT_FREQUENCY_COUNT_DIGIT)
            cout << "Digit " << counter << " Frequency is " << CURRENT_FREQUENCY_COUNT_DIGIT << " Time(s)" << endl;
    }
}

int main() { printAllDigits(readPositiveNumber()); }