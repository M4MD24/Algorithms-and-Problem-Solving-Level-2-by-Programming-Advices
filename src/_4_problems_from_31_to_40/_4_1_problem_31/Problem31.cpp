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

void fillWith1ToTargetNumber(
    int numbers[],
    int numberCount
) {
    while (numberCount--)
        numbers[numberCount] = numberCount + 1;
}

void swap(
    int& firstNumber,
    int& secondNumber
) {
    firstNumber += secondNumber;
    secondNumber = firstNumber - secondNumber;
    firstNumber -= secondNumber;
}

int randomNumber(
    const int FROM,
    const int TO
) { return rand() % (TO - FROM + 1) + FROM; }

void shuffleNumbers(
    int numbers[],
    const int NUMBER_COUNT
) {
    for (int counter = 0; counter < NUMBER_COUNT; counter++) {
        const int FIRST_INDEX = randomNumber(
                      1,
                      NUMBER_COUNT
                  ) - 1,
                  SECOND_INDEX = randomNumber(
                      1,
                      NUMBER_COUNT
                  ) - 1;
        swap(
            numbers[FIRST_INDEX],
            numbers[SECOND_INDEX]
        );
    }
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
    int numbers[NUMBER_COUNT];
    fillWith1ToTargetNumber(
        numbers,
        NUMBER_COUNT
    );

    cout << "Numbers before shuffle:" << endl;
    printNumbers(
        numbers,
        NUMBER_COUNT
    );

    shuffleNumbers(
        numbers,
        NUMBER_COUNT
    );

    cout << "\nNumbers after shuffle:" << endl;
    printNumbers(
        numbers,
        NUMBER_COUNT
    );
}