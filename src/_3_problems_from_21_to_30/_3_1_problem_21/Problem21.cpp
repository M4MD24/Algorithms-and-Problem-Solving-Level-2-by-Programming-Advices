#include <iostream>
using namespace std;

short readPositiveNumber() {
    short number;
    do {
        cout << "Enter positive number:" << endl;
        cin >> number;
    } while (number < 1);
    return number;
}

short randomNumber(const short FROM, const short TO) { return rand() % (TO - FROM + 1) + FROM; }

char randomCapitalCharacter() { return static_cast<char>(randomNumber('A', 'Z')); }

string generateCapitalCharactersWord(short length) {
    string word;
    while (length--)
        word += randomCapitalCharacter();
    return word;
}

string generateKey() {
    return generateCapitalCharactersWord(4) + '-' +
        generateCapitalCharactersWord(4) + '-' +
        generateCapitalCharactersWord(4) + '-' +
        generateCapitalCharactersWord(4);
}

void generateKeys(const short KEY_COUNT) {
    for (int counter = 1; counter <= KEY_COUNT; ++counter)
        cout << "Key [" << counter << "] = " << generateKey() << endl;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    generateKeys(readPositiveNumber());
}