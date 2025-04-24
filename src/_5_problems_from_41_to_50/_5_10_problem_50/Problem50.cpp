#include <cmath>
#include <iostream>
using namespace std;

double readNumber() {
    cout << "Enter number:" << endl;
    double number;
    cin >> number;
    return number;
}

double calculateSquareRoot(const double NUMBER) {
    return pow(NUMBER, 0.5);
}

int main() {
    const double NUMBER = readNumber();
    cout << "Manual Square Root = " << calculateSquareRoot(NUMBER) << endl;
    cout << "C++ Square Root = " << sqrt(NUMBER);
}