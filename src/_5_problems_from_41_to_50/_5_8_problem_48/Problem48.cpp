#include <cmath>
#include <iostream>
using namespace std;

float readNumber() {
    cout << "Enter number:" << endl;
    float number;
    cin >> number;
    return number;
}

float getFractionPart(const float NUMBER) { return NUMBER - static_cast<int>(NUMBER); }

int calculateFloorNumber(const float NUMBER) {
    if (
        const float FRACTION_PART = getFractionPart(NUMBER);
        abs(FRACTION_PART) > 0
    ) {
        if (NUMBER > 0)
            return static_cast<int>(NUMBER);
        return static_cast<int>(NUMBER - 1);
    }
    return static_cast<int>(NUMBER);
}

int main() {
    const float NUMBER = readNumber();
    cout << "Manual Floor = " << calculateFloorNumber(NUMBER) << endl;
    cout << "C++ Floor = " << floor(NUMBER);
}