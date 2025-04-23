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

void copyNumbers(
    const short ORIGINAL_NUMBERS[],
    short secondNumber[],
    int numberCount
) {
    while (numberCount--)
        secondNumber[numberCount] = ORIGINAL_NUMBERS[numberCount];
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int NUMBER_COUNT = readPositiveNumber();
    short firstNumbers[NUMBER_COUNT];
    short secondNumbers[NUMBER_COUNT];

    fillRandomNumbers(
        firstNumbers,
        NUMBER_COUNT
    );

    copyNumbers(
        firstNumbers,
        secondNumbers,
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
}