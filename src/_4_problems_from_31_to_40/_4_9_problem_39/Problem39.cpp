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

enum NumberStatus {
    NotPrime = 0,
    Prime = 1
};

NumberStatus checkNumber(const int NUMBER) {
    switch (NUMBER) {
    case 1:
        return NotPrime;
    case 2:
    case 3:
        return Prime;
    default:
        if (NUMBER % 2 == 0 || NUMBER % 3 == 0)
            return NotPrime;
        const int SQUARE_ROOT_NUMBER = static_cast<int>(sqrt(NUMBER));
        for (int counter = 5; counter <= SQUARE_ROOT_NUMBER; counter += 2)
            if (NUMBER % counter == 0)
                return NotPrime;
        return Prime;
    }
}

void copyPrimeNumbers(
    const int ORIGINAL_NUMBERS[],
    int anotherNumbers[],
    const int ORIGINAL_NUMBER_COUNT,
    int& anotherNumberCount
) {
    for (int index = 0; index < ORIGINAL_NUMBER_COUNT; ++index)
        if (
            const int CURRENT_NUMBER = ORIGINAL_NUMBERS[index];
            checkNumber(CURRENT_NUMBER) == Prime
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

    copyPrimeNumbers(
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