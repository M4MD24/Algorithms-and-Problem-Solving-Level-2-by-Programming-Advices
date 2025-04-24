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
            -100,
            100
        );
}

int positiveNumberCount(
    const short NUMBERS[],
    const int NUMBER_COUNT
) {
    int counter = 0;
    for (int index = 0; index < NUMBER_COUNT; ++index)
        if (NUMBERS[index] > 0)
            counter++;
    return counter;
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
    short numbers[NUMBER_COUNT];

    fillRandomNumbers(
        numbers,
        NUMBER_COUNT
        );

    printNumbers(
        numbers,
        NUMBER_COUNT
    );

    cout << endl << "Count of Positive Numbers: " << positiveNumberCount(
        numbers,
        NUMBER_COUNT
    );
}