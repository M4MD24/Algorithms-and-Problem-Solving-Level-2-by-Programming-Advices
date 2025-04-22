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

enum NumberStatus {
    NotPerfect = 0,
    Perfect = 1
};

NumberStatus isPerfect(const int NUMBER) {
    if (NUMBER <= 1)
        return NotPerfect;

    int sum = 1;
    for (
        int counter = 2;
        counter * counter <= NUMBER;
        ++counter
    )
        if (NUMBER % counter == 0) {
            sum += counter;
            if (counter != NUMBER / counter)
                sum += NUMBER / counter;
        }

    if (sum == NUMBER)
        return Perfect;
    return NotPerfect;
}

void printStatus(const int STATUS_NUMBER) {
    cout << "Is";
    if (STATUS_NUMBER == NotPerfect)
        cout << "n't";
    cout << " Perfect";
}

int main() { printStatus(isPerfect(readPositiveNumber())); }