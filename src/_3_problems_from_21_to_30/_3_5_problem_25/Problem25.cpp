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

int getMinimumNumber(
    const int NUMBERS[],
    int numberCount
) {
    int minimumNumber = NUMBERS[--numberCount];
    while (numberCount--)
        if (
            const int CURRENT_NUMBER = NUMBERS[numberCount];
            CURRENT_NUMBER < minimumNumber
        )
            minimumNumber = CURRENT_NUMBER;
    return minimumNumber;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int NUMBER_COUNT = readPositiveNumber();
    int numbers[NUMBER_COUNT];
    fillRandomNumbers(
        numbers,
        NUMBER_COUNT
    );

    cout << "Numbers: ";
    printNumbers(
        numbers,
        NUMBER_COUNT
    );

    cout << "\nMinimum Number: " << getMinimumNumber(
        numbers,
        NUMBER_COUNT
    );
}