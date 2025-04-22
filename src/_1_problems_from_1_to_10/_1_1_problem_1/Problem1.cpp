#include <iostream>
using namespace std;

string columnSeparator(const int NUMBER) {
    string columnSeparator = "    ";

    if (NUMBER < 10)
        columnSeparator += ' ';

    columnSeparator += '|';

    return columnSeparator;
}

void printTableHeader() {
    cout << "\t";

    for (int counter = 1; counter <= 12; ++counter)
        cout << counter << '\t';

    cout << endl << "       " << "--------------------------------------------------------------------------------------------" << endl;
}

void printTableBody() {
    for (int firstNumber = 1; firstNumber <= 12; ++firstNumber) {
        cout << firstNumber << columnSeparator(firstNumber) << '\t';
        for (int secondNumber = 1; secondNumber <= 12; ++secondNumber)
            cout << firstNumber * secondNumber << '\t';
        cout << endl;
    }
}

void printMultiplicationTable() {
    printTableHeader();
    printTableBody();
}

int main() { printMultiplicationTable(); }