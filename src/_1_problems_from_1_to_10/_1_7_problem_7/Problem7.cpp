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

int reversedNumber(int number) {
    int reversedNumber = 0;

    while (number != 0) {
        const int REMAINDER = number % 10;
        reversedNumber = reversedNumber * 10 + REMAINDER;
        number /= 10;
    }

    return reversedNumber;
}

int main() { cout << reversedNumber(readPositiveNumber()); }