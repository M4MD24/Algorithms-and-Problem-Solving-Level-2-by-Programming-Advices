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

short randomNumber(
    const short FROM,
    const short TO
) { return rand() % (TO - FROM + 1) + FROM; }

void fillRandomNumbers(
    short numbers[],
    int numberCount
) {
    while (numberCount--)
        numbers[numberCount] = randomNumber(
            1,
            100
        );
}

void printNumbers(
    const short NUMBERS[],
    const int NUMBER_COUNT
) {
    for (int index = 0; index < NUMBER_COUNT; ++index) {
        cout << NUMBERS[index];
        if (index < NUMBER_COUNT - 1)
            cout << ", ";
    }
}

enum NumberStatus {
    NotPrime = 0,
    Prime = 1
};

NumberStatus checkNumber(const short NUMBER) {
    switch (NUMBER) {
    case 1:
        return NotPrime;
    case 2:
    case 3:
        return Prime;
    default:
        if (NUMBER % 2 == 0 || NUMBER % 3 == 0)
            return NotPrime;
        const short SQUARE_ROOT_NUMBER = static_cast<short>(sqrt(NUMBER));
        for (short counter = 5; counter <= SQUARE_ROOT_NUMBER; counter += 2)
            if (NUMBER % counter == 0)
                return NotPrime;
        return Prime;
    }
}

void copyPrimeNumbers(
    const short FIRST_NUMBERS[],
    const int FIRST_NUMBER_COUNT,
    short secondNumber[],
    int& secondNumberCount
) {
    int primeNumberCount = 0;
    for (int index = 0; index < FIRST_NUMBER_COUNT; ++index)
        if (
            const short CURRENT_NUMBER = FIRST_NUMBERS[index];
            checkNumber(CURRENT_NUMBER) == Prime
        )
            secondNumber[primeNumberCount++] = CURRENT_NUMBER;
    secondNumberCount = primeNumberCount;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int FIRST_NUMBER_COUNT = readPositiveNumber();
    short firstNumbers[FIRST_NUMBER_COUNT];

    fillRandomNumbers(
        firstNumbers,
        FIRST_NUMBER_COUNT
    );

    short secondNumbers[FIRST_NUMBER_COUNT];
    int secondNumberCount = 0;

    copyPrimeNumbers(
        firstNumbers,
        FIRST_NUMBER_COUNT,
        secondNumbers,
        secondNumberCount
    );

    cout << "First Numbers:" << endl;
    printNumbers(
        firstNumbers,
        FIRST_NUMBER_COUNT
    );

    cout << "\nSecond Numbers:" << endl;
    printNumbers(
        secondNumbers,
        secondNumberCount
    );
}