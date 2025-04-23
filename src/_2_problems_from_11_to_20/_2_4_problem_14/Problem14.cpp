#include <iostream>
using namespace std;

int readCharacterNumber() {
    int characterNumber;
    do {
        cout << "Enter character number (Capital Letter):" << endl;
        cin >> characterNumber;
    } while (characterNumber + '@' < 'A' || characterNumber + '@' > 'Z');
    return characterNumber;
}

void repeatCharacter(const char CHARACTER) {
    for (char counter = CHARACTER; counter > '@'; --counter)
        cout << CHARACTER;
}

void printInvertedCharacterPattern(int characterNumber) {
    while (characterNumber > 0) {
        repeatCharacter(static_cast<char>(characterNumber-- + '@'));
        cout << endl;
    }
}

int main() { printInvertedCharacterPattern(readCharacterNumber()); }