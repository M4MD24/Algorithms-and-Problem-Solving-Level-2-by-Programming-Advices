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

int sumOfDigits(int number) {
    int sum = 0;
    while (number != 0) {
        const int REMAINDER = number % 10;
        number /= 10;
        sum += REMAINDER;
    }
    return sum;
}

void printSumOfDigits(const int SUM_OF_DIGITS) { cout << "Sum of digits is: " << SUM_OF_DIGITS; }

int main() { printSumOfDigits(sumOfDigits(readPositiveNumber())); }