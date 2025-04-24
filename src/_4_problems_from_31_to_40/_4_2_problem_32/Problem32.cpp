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

void copyNumbersInReverseOrder(
    const short ORIGINAL_NUMBERS[],
    short anotherNumbers[],
    const int NUMBER_COUNT
) {
    for (
        int originalIndex = 0, anotherIndex = NUMBER_COUNT - 1;
        originalIndex < NUMBER_COUNT;
        ++originalIndex, --anotherIndex
    )
        anotherNumbers[originalIndex] = ORIGINAL_NUMBERS[anotherIndex];
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int NUMBER_COUNT = readPositiveNumber();
    short originalNumbers[NUMBER_COUNT];
    short anotherNumbers[NUMBER_COUNT];

    fillRandomNumbers(
        originalNumbers,
        NUMBER_COUNT
    );

    copyNumbersInReverseOrder(
        originalNumbers,
        anotherNumbers,
        NUMBER_COUNT
    );

    cout << "First Numbers:" << endl;
    printNumbers(
        originalNumbers,
        NUMBER_COUNT
    );

    cout << "\nSecond Numbers:" << endl;
    printNumbers(
        anotherNumbers,
        NUMBER_COUNT
    );
}