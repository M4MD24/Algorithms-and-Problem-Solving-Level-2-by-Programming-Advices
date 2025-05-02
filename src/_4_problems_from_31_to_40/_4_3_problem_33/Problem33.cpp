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

void generateKeys(
    string keys[],
    int keyCount
) {
    while (keyCount--)
        keys[keyCount] = generateKey();
}

void printKeys(
    const string KEYS[],
    const int KEY_COUNT
) {
    for (int index = 0; index < KEY_COUNT; ++index)
        cout << "Key [" << index + 1 << "] = " << KEYS[index] << endl;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int KEY_COUNT = readPositiveNumber();
    string keys[KEY_COUNT];

    generateKeys(
        keys,
        KEY_COUNT
    );

    printKeys(
        keys,
        KEY_COUNT
    );
}