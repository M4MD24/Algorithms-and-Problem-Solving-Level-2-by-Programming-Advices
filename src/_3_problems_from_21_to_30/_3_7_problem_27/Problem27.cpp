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

long numbersSum(
    const int NUMBERS[],
    int numberCount
) {
    long sum = 0;
    while (numberCount--)
        sum += NUMBERS[numberCount];
    return sum;
}

double averageNumbers(
    const long NUMBERS_SUM,
    const int NUMBER_COUNT
) { return NUMBERS_SUM / static_cast<double>(NUMBER_COUNT); }

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

    const long NUMBERS_SUM = numbersSum(
        numbers,
        NUMBER_COUNT
    );

    cout << "\nAverage of Numbers: " << averageNumbers(
        NUMBERS_SUM,
        NUMBER_COUNT
    );
}