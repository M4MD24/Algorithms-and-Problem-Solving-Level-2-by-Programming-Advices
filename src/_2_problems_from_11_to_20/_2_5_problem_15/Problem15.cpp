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

void printCharacterPattern(const int NUMBER) {
    for (char currentCharacter = 'A'; currentCharacter <= NUMBER + '@'; ++currentCharacter) {
        repeatCharacter(currentCharacter);
        cout << endl;
    }
}

int main() { printCharacterPattern(readCharacterNumber()); }