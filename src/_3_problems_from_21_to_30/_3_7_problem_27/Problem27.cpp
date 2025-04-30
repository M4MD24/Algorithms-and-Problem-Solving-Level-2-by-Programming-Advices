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

long long numbersSum(
    const short NUMBERS[],
    int numberCount
) {
    long long sum = 0;
    while (numberCount--)
        sum += NUMBERS[numberCount];
    return sum;
}

double averageNumbers(
    const long long NUMBERS_SUM,
    const int NUMBER_COUNT
) { return NUMBERS_SUM / static_cast<double>(NUMBER_COUNT); }

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int NUMBER_COUNT = readPositiveNumber();
    short numbers[NUMBER_COUNT];
    fillRandomNumbers(
        numbers,
        NUMBER_COUNT
    );

    cout << "Numbers: ";
    printNumbers(
        numbers,
        NUMBER_COUNT
    );

    const long long NUMBERS_SUM = numbersSum(
        numbers,
        NUMBER_COUNT
    );

    cout << "\nAverage of Numbers: " << averageNumbers(
        NUMBERS_SUM,
        NUMBER_COUNT
    );
}