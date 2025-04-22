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

int calculateDivisor(const int NUMBER) {
    int divisor = 1;
    while (NUMBER / divisor >= 10)
        divisor *= 10;
    return divisor;
}

void printDigitsInOrder(int number) {
    int divisor = calculateDivisor(number);

    while (divisor != 0) {
        const int DIGIT = number / divisor;
        cout << DIGIT << endl;
        number %= divisor;
        divisor /= 10;
    }
}

int main() { printDigitsInOrder(readPositiveNumber()); }