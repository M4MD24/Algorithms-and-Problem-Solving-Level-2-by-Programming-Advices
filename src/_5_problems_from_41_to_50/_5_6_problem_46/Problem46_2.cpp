#include <iostream>
using namespace std;

float readNumber() {
    cout << "Enter number:" << endl;
    float number;
    cin >> number;
    return number;
}

float calculateAbsoluteNumber(const float NUMBER) {
    if (NUMBER < 0)
        return NUMBER * -1;
    return NUMBER;
}

int main() {
    const float NUMBER = readNumber();
    cout << "Absolute Value = " << calculateAbsoluteNumber(NUMBER) << endl;
    cout << "C++ absolute value = " << abs(NUMBER);
}