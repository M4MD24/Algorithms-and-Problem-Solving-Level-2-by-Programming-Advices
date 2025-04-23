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

void repeatNumber(const int NUMBER) {
    for (int counter = NUMBER; counter > 0; --counter)
        cout << NUMBER;
}

void printNumberPatternInOrder(const int NUMBER) {
    for (int currentNumber = 1; currentNumber <= NUMBER; ++currentNumber) {
        repeatNumber(currentNumber);
        cout << endl;
    }
}

int main() { printNumberPatternInOrder(readPositiveNumber()); }