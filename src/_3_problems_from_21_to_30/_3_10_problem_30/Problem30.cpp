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

void calculateSumBetweenFirstAndSecondNumbers(
    const short FIRST_NUMBERS[],
    const short SECOND_NUMBERS[],
    short numbersSumBetweenFirstAndSecondNumbers[],
    int numberCount
) {
    while (numberCount--)
        numbersSumBetweenFirstAndSecondNumbers[numberCount] = FIRST_NUMBERS[numberCount] + SECOND_NUMBERS[numberCount];
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

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int NUMBER_COUNT = readPositiveNumber();
    short firstNumbers[NUMBER_COUNT];
    short secondNumbers[NUMBER_COUNT];
    short numbersSumBetweenFirstAndSecondNumbers[NUMBER_COUNT];

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