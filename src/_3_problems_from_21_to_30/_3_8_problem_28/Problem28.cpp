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

void copyNumbers(
    const int FIRST_NUMBERS[],
    int secondNumber[],
    int numberCount
) {
    while (numberCount--)
        secondNumber[numberCount] = FIRST_NUMBERS[numberCount];
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int NUMBER_COUNT = readPositiveNumber();
    int firstNumbers[NUMBER_COUNT];

    fillRandomNumbers(
        firstNumbers,
        NUMBER_COUNT
    );

    int secondNumbers[NUMBER_COUNT];

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