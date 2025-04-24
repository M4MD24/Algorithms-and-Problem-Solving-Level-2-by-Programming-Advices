#include <iostream>
using namespace std;

int readNumber() {
    cout << "Enter number:" << endl;
    int number;
    cin >> number;
    return number;
}

void addNumber(
    const int NUMBER,
    int numbers[100],
    int& numberCount
) { numbers[numberCount++] = NUMBER; }

void readNumbers(
    int numbers[],
    int& numberCount
) {
    bool canReadNumber = true;
    do {
        const int NUMBER = readNumber();
        addNumber(
            NUMBER,
            numbers,
            numberCount
        );

        cout << "Add more numbers?" << endl;
        cin >> canReadNumber;
    } while (canReadNumber);
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
    int numberCount = 0;
    int numbers[numberCount];
    readNumbers(
        numbers,
        numberCount
    );

    cout << "Number Count: " << numberCount << endl;
    cout << "Numbers: ";
    printNumbers(
        numbers,
        numberCount
    );
}