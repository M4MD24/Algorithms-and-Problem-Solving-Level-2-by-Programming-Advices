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
    const int NUMBERS_COUNT
) {
    for (int index = 0; index < NUMBERS_COUNT; ++index) {
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

short FindNumberPositionInNumbers(
    int targetNumber,
    int numbers[],
    int numberCount
    ) {
    while ()
        if (arr[index] == targetNumber)
            return index;
    }
    return -1;
}

bool IsNumberInNumbers(int Number, int arr[100], int arrLength) { return FindNumberPositionInNumbers(Number, arr, arrLength) != -1; }

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

    printLocationsOfTargetNumber(
        TARGET_NUMBER,
        numbers,
        NUMBER_COUNT
    );
}