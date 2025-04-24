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

void readNumbers(
    int numbers[],
    const int NUMBER_COUNT
) {
    for (int index = 0; index < NUMBER_COUNT; ++index) {
        cout << "Element [" << index + 1 << "]:" << endl;
        cin >> numbers[index];
    }
}

int readNumber() {
    cout << "Enter number:" << endl;
    int number;
    cin >> number;
    return number;
}

void printNumbers(
    const int NUMBERS[],
    const int NUMBER_COUNT
) {
    for (int index = 0; index < NUMBER_COUNT; ++index) {
        cout << NUMBERS[index];
        if (index < NUMBER_COUNT - 1)
            cout << ", ";
    }
}

int FindNumberPositionInNumbers(
    const int TARGET_NUMBER,
    const int numbers[],
    const int NUMBER_COUNT
) {
    for (int index = 0; index < NUMBER_COUNT; ++index)
        if (numbers[index] == TARGET_NUMBER)
            return index;
    return -1;
}

bool IsNumberInNumbers(
    const int TARGET_NUMBER,
    const int numbers[],
    const int NUMBER_COUNT
) {
    return FindNumberPositionInNumbers(
        TARGET_NUMBER,
        numbers,
        NUMBER_COUNT
    ) != -1;
}

void printStatus(const bool STATUS) {
    if (STATUS)
        cout << "Found";
    else
        cout << "Not Found";
}

int main() {
    const int NUMBER_COUNT = readPositiveNumber();
    int numbers[NUMBER_COUNT];
    readNumbers(
        numbers,
        NUMBER_COUNT
    );
    const int TARGET_NUMBER = readNumber();

    cout << "Numbers: ";
    printNumbers(
        numbers,
        NUMBER_COUNT
    );

    cout << endl;

    printStatus(
        IsNumberInNumbers(
            TARGET_NUMBER,
            numbers,
            NUMBER_COUNT
        )
    );
}