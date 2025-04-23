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

int randomNumber(
    const int FROM,
    const int TO
) { return rand() % (TO - FROM + 1) + FROM; }

void fillRandomNumbers(
    int numbers[],
    int numberCount
) {
    while (numberCount--)
        numbers[numberCount] = randomNumber(
            1,
            100
        );
}

void calculateSumBetweenFirstAndSecondNumbers(
    const int FIRST_NUMBERS[],
    const int SECOND_NUMBERS[],
    int numbersSumBetweenFirstAndSecondNumbers[],
    int numberCount
) {
    while (numberCount--)
        numbersSumBetweenFirstAndSecondNumbers[numberCount] = FIRST_NUMBERS[numberCount] + SECOND_NUMBERS[numberCount];
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
    srand(static_cast<unsigned>(time(nullptr)));

    const int NUMBER_COUNT = readPositiveNumber();
    int firstNumbers[NUMBER_COUNT];
    int secondNumbers[NUMBER_COUNT];
    int numbersSumBetweenFirstAndSecondNumbers[NUMBER_COUNT];

    fillRandomNumbers(
        firstNumbers,
        NUMBER_COUNT
    );
    fillRandomNumbers(
        secondNumbers,
        NUMBER_COUNT
    );

    calculateSumBetweenFirstAndSecondNumbers(
        firstNumbers,
        secondNumbers,
        numbersSumBetweenFirstAndSecondNumbers,
        NUMBER_COUNT
    );

    cout << "First Numbers:" << endl;
    printNumbers(
        firstNumbers,
        NUMBER_COUNT
    );

    cout << "\nSecond Numbers:" << endl;
    printNumbers(
        secondNumbers,
        NUMBER_COUNT
    );

    cout << "\nSum of Numbers Between First and Second Numbers:" << endl;
    printNumbers(
        numbersSumBetweenFirstAndSecondNumbers,
        NUMBER_COUNT
    );
}