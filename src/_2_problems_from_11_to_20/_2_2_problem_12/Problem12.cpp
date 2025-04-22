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

void printInvertedNumberPattern(int number) {
    while (number > 0) {
        repeatNumber(number--);
        cout << endl;
    }
}

int main() { printInvertedNumberPattern(readPositiveNumber()); }