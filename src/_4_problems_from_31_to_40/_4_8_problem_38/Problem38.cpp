#include <cmath>
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

void addNumber(
    const int NUMBER,
    int numbers[],
    int& numberCount
) { numbers[numberCount++] = NUMBER; }

void readNumbers(
    int numbers[],
    const int NUMBER_COUNT
) {
    for (int index = 0; index < NUMBER_COUNT; ++index) {
        cout << "Element [" << index + 1 << "]:" << endl;
        cin >> numbers[index];
    }
}

void copyOddNumbers(
    const int ORIGINAL_NUMBERS[],
    int anotherNumbers[],
    const int ORIGINAL_NUMBER_COUNT,
    int& anotherNumberCount
) {
    for (int index = 0; index < ORIGINAL_NUMBER_COUNT; ++index)
        if (
            const int CURRENT_NUMBER = ORIGINAL_NUMBERS[index];
            CURRENT_NUMBER % 2 != 0
        )
            addNumber(
                CURRENT_NUMBER,
                anotherNumbers,
                anotherNumberCount
            );
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

int main() {
    const int ORIGINAL_NUMBER_COUNT = readPositiveNumber();
    int originalNumbers[ORIGINAL_NUMBER_COUNT];
    int anotherNumberCount = 0;
    int anotherNumbers[ORIGINAL_NUMBER_COUNT];

    readNumbers(
        originalNumbers,
        ORIGINAL_NUMBER_COUNT
    );

    copyOddNumbers(
        originalNumbers,
        anotherNumbers,
        ORIGINAL_NUMBER_COUNT,
        anotherNumberCount
    );

    cout << "Original Numbers: ";
    printNumbers(
        originalNumbers,
        ORIGINAL_NUMBER_COUNT
    );

    cout << "\nAnother Numbers: ";
    printNumbers(
        anotherNumbers,
        anotherNumberCount
    );
}