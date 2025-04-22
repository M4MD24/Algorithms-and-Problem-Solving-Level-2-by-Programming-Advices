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

void printDigits(int number) {
    while (number != 0) {
        const int REMAINDER = number % 10;
        number /= 10;
        cout << REMAINDER << endl;
    }
}

int main() { printDigits(readPositiveNumber()); }