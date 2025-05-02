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

void fillNumbers(
    int numbers[]
) {
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 30;
    numbers[4] = 20;
    numbers[5] = 10;
}

bool isPalindromeNumbers(
    const int NUMBERS[],
    const int NUMBER_COUNT
) {
    for (int index = 0; index < NUMBER_COUNT / 2; ++index)
        if (NUMBERS[index] != NUMBERS[NUMBER_COUNT - 1 - index])
            return false;
    return true;
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

void printStatus(const bool STATUS) {
    cout << "Is";
    if (!STATUS)
        cout << "n't";
    cout << " Palindrome";
}

int main() {
    const int NUMBER_COUNT = 6;
    int numbers[NUMBER_COUNT];

    fillNumbers(numbers);

    printNumbers(
        numbers,
        NUMBER_COUNT
    );

    cout << endl;

    printStatus(
        isPalindromeNumbers(
            numbers,
            NUMBER_COUNT
        )
    );
}